#include <algorithm>
#include <array>
#include <unordered_map>
#include <vector>

// TW: dastardly bit manip

class Solution {
 private:
  int trailing_zeros(unsigned x) {
    if (x == 0) {
      return 32;
    }
    return __builtin_ctz(x);
  }

  std::unordered_map<int, unsigned> getAllBoardPossibleValues(
      std::vector<std::vector<char>>& board) {
    int h = board.size();
    int n_cells = h * h;

    std::unordered_map<int, unsigned> result;
    for (int i = 0; i < n_cells; i++) {
      int x = i / h;
      int y = i % h;
      if (board[x][y] != '.') {
        result[i] = 0;
        continue;
      }

      result[i] = getSquarePossibilities(board, x, y);
    }

    return result;
  }

  unsigned getSquarePossibilities(std::vector<std::vector<char>>& board, int x,
                                  int y) {
    unsigned possibilities = 0x1FF;

    int h = board.size();

    // check row
    for (int j = 0; j < h; j++) {
      int val = board[x][j];
      if (val != '.') {
        possibilities &= ~(1 << (val - '1'));
      }
    }

    // check column
    for (int j = 0; j < h; j++) {
      int val = board[j][y];
      if (val != '.') {
        possibilities &= ~(1 << (val - '1'));
      }
    }

    // check square
    for (int a = 0; a < 3; a++) {
      for (int b = 0; b < 3; b++) {
        int x_square = x / 3 * 3 + a;
        int y_square = y / 3 * 3 + b;
        int val = board[x_square][y_square];
        if (val != '.') {
          possibilities &= ~(1 << (val - '1'));
        }
      }
    }

    return possibilities;
  }

  void updateCell(std::vector<std::vector<char>>& board,
                  std::unordered_map<int, unsigned>& possibilities, int x,
                  int y, char new_value) {
    int h = board.size();

    board[x][y] = new_value;
    possibilities[x * h + y] = 0;

    int new_mask = ~(1 << (new_value - '1'));

    // update row
    for (int a = 0; a < h; a++) {
      if (board[x][a] == '.') {
        possibilities[x * h + a] &= new_mask;
      }
    }
    // update column
    for (int b = 0; b < h; b++) {
      if (board[b][y] == '.') {
        possibilities[b * h + y] &= new_mask;
      }
    }
    // update square
    for (int a = 0; a < 3; a++) {
      for (int b = 0; b < 3; b++) {
        int x_square = x / 3 * 3 + a;
        int y_square = y / 3 * 3 + b;
        if (board[x_square][y_square] == '.') {
          possibilities[x_square * h + y_square] &= new_mask;
        }
      }
    }
  }

  bool isSolved(std::vector<std::vector<char>>& board) {
    int h = board.size();
    int n_cells = h * h;

    for (int i = 0; i < n_cells; i++) {
      int x = i / h;
      int y = i % h;
      if (board[x][y] == '.') {
        return false;
      }
    }
    return true;
  }

 public:
  void solveSudoku(std::vector<std::vector<char>>& board) {
    int h = board.size();
    int n_cells = h * h;

    std::unordered_map<int, unsigned> possibilities =
        getAllBoardPossibleValues(board);

    // change cells with only one possibility
    bool solved = false;

    // stack of board states
    std::vector<std::vector<std::vector<char>>> board_states;
    // stack of possibilities states
    std::vector<std::unordered_map<int, unsigned>> possibilities_states;
    // stack of choices (pos, value)
    std::vector<std::pair<int, char>> choices;
    while (!solved) {
      bool changed = true;
      bool valid_board = true;
      while (changed) {
        changed = false;
        bool possibilities_left = false;
        for (int i = 0; i < n_cells; i++) {
          int x = i / h;
          int y = i % h;
          if (board[x][y] != '.') {
            continue;
          }
          unsigned possible_values = possibilities[i];

          // only one bit is set
          if (__builtin_popcount(possible_values) == 1) {
            char new_value = trailing_zeros(possible_values) + '1';
            updateCell(board, possibilities, x, y, new_value);
            changed = true;
          } else if (possible_values == 0) {
            // there's a contradiction
            valid_board = false;
            break;
          } else {
            possibilities_left = true;
          }
        }
        if (!valid_board) {
          break;
        }
        if (!possibilities_left) {
          solved = true;
          break;
        }
      }

      if (!valid_board) {
        // go back
        bool go_back = true;
        while (go_back) {
          // pop stuff
          board = board_states.back();
          possibilities = possibilities_states.back();
          std::pair<int, char> last_choice = choices.back();

          // get new possibility
          int old_j = last_choice.first;
          int old_index = last_choice.second - '1';
          unsigned poss = possibilities[old_j];
          int new_value = trailing_zeros(poss & ~(0x1FF >> (8 - old_index)));
          if (new_value == 32) {
            // no more possibilities
            board_states.pop_back();
            possibilities_states.pop_back();
            choices.pop_back();
            continue;
          }
          go_back = false;

          int x = old_j / h;
          int y = old_j % h;

          char new_char = new_value + '1';
          updateCell(board, possibilities, x, y, new_char);

          // push new choice
          choices.pop_back();
          choices.push_back(std::make_pair(last_choice.first, new_char));
        }

        continue;
      }

      if (solved) {
        break;
      }

      // a choice must be made
      // check for square with least amount of possibilities
      int min_possibilities = 10;
      int min_i = -1;
      for (int i = 0; i < n_cells; i++) {
        unsigned possible_values = possibilities[i];
        int n_possibilities = __builtin_popcount(possible_values);
        if (n_possibilities > 1 && n_possibilities < min_possibilities) {
          min_possibilities = n_possibilities;
          min_i = i;
        }
      }

      if (min_i == -1) {
        // no more choices
        solved = true;
        break;
      }

      // try possibility
      // copy board and possibilities
      board_states.push_back(board);
      possibilities_states.push_back(possibilities);

      int x = min_i / h;
      int y = min_i % h;
      unsigned possible_values = possibilities[min_i];
      char new_value = trailing_zeros(possible_values) + '1';

      choices.push_back(std::make_pair(min_i, new_value));

      updateCell(board, possibilities, x, y, new_value);
    }
  }
};
