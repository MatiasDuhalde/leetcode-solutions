/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <climits>
#include <vector>

class Solution {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    // move all negative numbers to the end
    int h = nums.size();
    int l = 0;
    int r = h - 1;
    while (l < r) {
      if (nums[l] <= 0) {
        std::swap(nums[l], nums[r]);
        r--;
      } else {
        l++;
      }
    }

    int n = l;
    if (l < h && nums[l] > 0) {
      n++;
    }

    // place every number in their respective position
    for (int i = 0; i < n; i++) {
      int current = nums[i];
      if (current <= n) {
        int target = nums[current - 1];
        if (target != current) {
          nums[i] = target;
          nums[current - 1] = current;
          i--;
        }
      }
    }

    // find first value not in order
    for (int i = 1; i <= n; i++) {
      if (nums[i - 1] != i) {
        return i;
      }
    }

    return n + 1;
  }
};
// @lc code=end
