/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start

#include <vector>
class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    std::vector<int> res;
    const int width = matrix[0].size();
    const int height = matrix.size();

    int k = 0;
    int direction = 0;
    int loops = 0;
    while (k < width * height) {
      if (direction == 0) {
        for (int col = loops; col < width - loops; col++) {
          res.push_back(matrix[loops][col]);
          k++;
        }
        direction = 1;
      } else if (direction == 1) {
        for (int row = loops + 1; row < height - loops; row++) {
          res.push_back(matrix[row][width - loops - 1]);
          k++;
        }
        direction = 2;
      } else if (direction == 2) {
        for (int col = width - loops - 2; col > loops - 1; col--) {
          res.push_back(matrix[height - loops - 1][col]);
          k++;
        }
        direction = 3;
      } else if (direction == 3) {
        for (int row = height - loops - 2; row > loops; row--) {
          res.push_back(matrix[row][loops]);
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
