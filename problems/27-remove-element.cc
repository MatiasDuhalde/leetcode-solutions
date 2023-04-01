/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    int s = nums.size();
    for (int i = 0; i < s; i++) {
      if (nums[i] == val) {
        nums[i] = nums[s - 1];
        i--;
        s--;
      }
    }
    return s;
  }
};// @lc code=end
