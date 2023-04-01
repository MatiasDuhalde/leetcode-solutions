/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int jump(std::vector<int>& nums) {
    int n = nums.size();
    int current_jumps = 0;
    int current_index = 0;
    int step = nums[current_index];
    while (current_index < n - 1) {
      step = nums[current_index];
      if (step + current_index >= n - 1) {
        return current_jumps + 1;
      }
      int max_reach_index = current_index;
      int max_reach = current_index;
      for (int i = current_index + 1; i <= current_index + step; i++) {
        int reach = i + nums[i];
        if (reach > max_reach) {
          max_reach = reach;
          max_reach_index = i;
        }
      }
      current_index = max_reach_index;
      current_jumps++;
    }
    return current_jumps;
  }
};
// @lc code=end
