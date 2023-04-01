/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    int size = nums.size();

    int closest = INT_MAX;
    int closest_sum;
    for (int i = 0; i < size - 2;) {
      int a = nums[i];
      if (i > 0 && a == nums[i - 1]) {
        continue;
      }

      int left = i + 1;
      int right = size - 1;
      while (left < right) {
        int b = nums[left];
        int c = nums[right];
        int sum = a + b + c;
        int diff = sum - target;
        int abs_diff = abs(diff);
        if (abs_diff < closest) {
          closest = abs_diff;
          closest_sum = sum;
        }
        if (diff == 0) {
          return target;
        } else if (diff < 0) {
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
    return closest_sum;
  }
};
// @lc code=end
