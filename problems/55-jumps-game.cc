/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jumps Game
 */

// @lc code=start
#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    if (nums.size() == 1) {
      return true;
    }
    int i = nums.size() - 2;
    int jumpNeeded = 0;
    while (i >= 0) {
      if (nums[i] == 0) {
        jumpNeeded++;
      } else if (jumpNeeded > 0 && nums[i] <= jumpNeeded) {
        jumpNeeded++;
      } else {
        jumpNeeded = 0;
      }
      i--;
    }
    return jumpNeeded == 0;
  }
};
// @lc code=end
