/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    std::vector<int> current;
    std::vector<bool> used(n, false);
    std::vector<std::vector<int>> positions;
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
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
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
