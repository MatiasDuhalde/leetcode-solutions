/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First And Last Position Of Element In Sorted Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    int nums_length = nums.size();
    if (nums_length == 0) {
      return {-1, -1};
    }
    // search left
    int l = 0;
    int r = nums_length - 1;
    bool found = false;
    int current_left;
    while (l < r) {
      int current_middle = (l + r) / 2;
      int current_value = nums[current_middle % nums_length];
      if (current_value == target) {
        found = true;
        current_left = current_middle;
        r = current_middle - 1;
      } else if (target < current_value) {
        r = current_middle - 1;
      } else {
        l = current_middle + 1;
      }
    }
    if (l < nums_length && nums[l] == target) {
      found = true;
      current_left = l;
    }
    if (!found) {
      return {-1, -1};
    }

    // search right
    l = 0;
    r = nums_length - 1;
    int current_right;
    while (l < r) {
      int current_middle = (l + r) / 2;
      int current_value = nums[current_middle % nums_length];
      if (current_value == target) {
        found = true;
        current_right = current_middle;
        l = current_middle + 1;
      }
      if (target < current_value) {
        r = current_middle - 1;
      } else {
        l = current_middle + 1;
      }
    }
    if (nums[r] == target) {
      current_right = r;
    }

    return {current_left, current_right};
  }
};
// @lc code=end
