/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char val = board[i][j];
        if (val != '.') {
          for (int k = j + 1; k < 9; k++) {
            if (val == board[i][k]) {
              return false;
            }
          }
          for (int k = i + 1; k < 9; k++) {
            if (val == board[k][j]) {
              return false;
            }
          }
        }
      }
    }
    for (int sqi = 0; sqi < 3; sqi++) {
      for (int sqj = 0; sqj < 3; sqj++) {
        for (int i = sqi * 3; i < (sqi + 1) * 3; i++) {
          for (int j = sqj * 3; j < (sqj + 1) * 3; j++) {
            char val = board[i][j];
            if (val != '.') {
              for (int m = i; m < (sqi + 1) * 3; m++) {
                for (int n = m == i ? j + 1 : sqj * 3; n < (sqj + 1) * 3; n++) {
                  if (val == board[m][n]) {
                    return false;
                  }
                }
              }
            }
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end
