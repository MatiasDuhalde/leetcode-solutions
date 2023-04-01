/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> result;

    int size = nums.size();
    for (int i = 0; i < size;) {
      int a = nums[i];

      // If the current number is the same as the previous one, skip it.
      if (i > 0 && a == nums[i - 1]) {
        continue;
      }

      int target = -a;
      int left = i + 1;
      int right = size - 1;
      while (left < right) {
        int b = nums[left];
        int c = nums[right];
        int sum = b + c;
        if (target == b + c) {
          result.push_back({a, b, c});

          while (left < right && nums[left] == b) {
            left++;
          }
          while (left < right && nums[right] == c) {
            right--;
          }
        } else if (sum < target) {
          while (left < right && nums[left] == b) {
            left++;
          }
        } else {
          while (left < right && nums[right] == c) {
            right--;
          }
        }
      }
      while (i < size && nums[i] == a) {
        i++;
      }
    }
    return result;
  }
};
// @lc code=end
