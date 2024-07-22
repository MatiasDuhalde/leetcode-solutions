/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start

#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> res(n, std::vector<int>(n));
    int k = 0;
    int direction = 0;
    int loops = 0;

    while (k < n * n) {
      if (direction == 0) {
        for (int col = loops; col < n - loops; col++) {
          res[loops][col] = k + 1;
          k++;
        }
        direction = 1;
      } else if (direction == 1) {
        for (int row = loops + 1; row < n - loops; row++) {
          res[row][n - loops - 1] = k + 1;
          k++;
        }
        direction = 2;
      } else if (direction == 2) {
        for (int col = n - loops - 2; col > loops - 1; col--) {
          res[n - loops - 1][col] = k + 1;
          k++;
        }
        direction = 3;
      } else if (direction == 3) {
        for (int row = n - loops - 2; row > loops; row--) {
          res[row][loops] = k + 1;
          k++;
        }
        loops++;
        direction = 0;
      }
    }

    return res;
  }
};
// @lc code=end
