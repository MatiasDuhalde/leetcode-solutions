/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum Of 1D Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> runningSum(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> v(size);
    v[0] = nums[0];
    for (int i = 1; i < size; i++) {
      v[i] = nums[i] + v[i - 1];
    }
    return v;
  }
};
// @lc code=end
