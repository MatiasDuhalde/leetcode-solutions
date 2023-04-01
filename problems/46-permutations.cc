/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> res;
    std::vector<int> current;
    std::vector<bool> used(n, false);
    dfs(nums, used, current, res);
    return res;
  }

  void dfs(std::vector<int>& nums, std::vector<bool>& used,
           std::vector<int>& current, std::vector<std::vector<int>>& res) {
    int n = nums.size();
    if (current.size() == n) {
      res.push_back(current);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (used[i]) {
        continue;
      }
      used[i] = true;
      current.push_back(nums[i]);
      dfs(nums, used, current, res);
      current.pop_back();
      used[i] = false;
    }
  }
};
// @lc code=end
