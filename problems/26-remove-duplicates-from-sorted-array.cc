/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates From Sorted Array Copy
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int s = nums.size();
    if (s < 2) return s;
    int i = 0;
    for (int j = 1; j < s; j++) {
      if (nums[i] != nums[j]) {
        nums[++i] = nums[j];
      }
    }
    return i + 1;
  }
};
// @lc code=end
