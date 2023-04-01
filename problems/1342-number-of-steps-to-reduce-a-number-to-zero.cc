/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number Of Steps To Reduce A Number To Zero
 */

// @lc code=start
class Solution {
 public:
  int numberOfSteps(int num) {
    if (num == 0) return 0;
    if (num % 2 == 0) return numberOfSteps(num / 2) + 1;
    return numberOfSteps(num - 1) + 1;
  }
};
// @lc code=end
