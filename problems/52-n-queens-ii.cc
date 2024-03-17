/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
  int totalNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> board(n, std::string(n, '.'));
    backtrack(res, board, n, 0, 0);
    return res.size();
  }

  void backtrack(std::vector<std::vector<std::string>> &res,
                 std::vector<std::string> &board, const int size, const int row,
                 const int placedQueens) {

    for (int col = 0; col < size; col++) {
      if (canPlaceQueen(board, size, row, col)) {
        board[row][col] = 'Q';
        if (placedQueens + 1 == size) {
          res.push_back(std::vector<std::string>(board));
          board[row][col] = '.';
          return;
        } else {
          backtrack(res, board, size, row + 1, placedQueens + 1);
          board[row][col] = '.';
        }
      }
    }
  }

  bool canPlaceQueen(std::vector<std::string> &board, int size, int row,
                     int col) {
    // check row
    for (int i = 0; i < size; i++) {
      if (board[row][i] == 'Q')
        return false;
    }
    // check col
    for (int j = 0; j < size; j++) {
      if (board[j][col] == 'Q')
        return false;
    }
    // check diagonals
    int i = col - 1;
    int j = row - 1;
    while (i >= 0 && j >= 0) {
      if (board[j][i] == 'Q')
        return false;
      i--;
      j--;
    }
    i = col - 1;
    j = row + 1;
    while (i >= 0 && j < size) {
      if (board[j][i] == 'Q')
        return false;
      i--;
      j++;
    }
    i = col + 1;
    j = row - 1;
    while (i < size && j >= 0) {
      if (board[j][i] == 'Q')
        return false;
      i++;
      j--;
    }
    i = col + 1;
    j = row + 1;
    while (i < size && j < size) {
      if (board[j][i] == 'Q')
        return false;
      i++;
      j++;
    }
    return true;
  }
};
// @lc code=end
