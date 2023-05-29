/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
      for (int j = i; j < n - i - 1; j++) {
        std::swap(matrix[i][j], matrix[j][n - 1 - i]);
        std::swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
        std::swap(matrix[i][j], matrix[n - 1 - j][i]);
      }
    }
  }
};
// @lc code=end
