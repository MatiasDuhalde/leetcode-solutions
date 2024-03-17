/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <climits>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    int s = 0;
    int e = 0;
    int maxSum = INT_MIN;
    int currentSum = 0;
    while (e < nums.size()) {
      currentSum += nums[e];
      if (currentSum > maxSum) {
        maxSum = currentSum;
        e++;
        if (nums[s] < 0) {
          currentSum -= nums[s];
          s++;
        }
      } else {
        if (currentSum > 0) {
          e++;
        } else {
          e++;
          s = e;
          currentSum = 0;
        }
      }
    }
    return maxSum;
  }
};
// @lc code=end
