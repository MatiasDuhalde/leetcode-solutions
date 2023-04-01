/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int trap(std::vector<int>& height) {
    int n = height.size();
    std::vector<int> minmax(n);

    // store left
    int current_max = 0;
    for (int i = 0; i < n; i++) {
      minmax[i] = current_max;
      if (height[i] > current_max) {
        current_max = height[i];
      }
    }

    // store right
    current_max = 0;
    for (int i = n - 1; i >= 0; i--) {
      minmax[i] = std::min(minmax[i], current_max);
      if (height[i] > current_max) {
        current_max = height[i];
      }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
      int val = minmax[i] - height[i];
      if (val > 0) {
        total += val;
      }
    }

    return total;
  }
};// @lc code=end
