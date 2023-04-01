/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
#include <cmath>
#include <vector>

class Solution {
 public:
  int maximumWealth(std::vector<std::vector<int>>& accounts) {
    int max_wealth = 0;
    int m = accounts.size();
    for (int i = 0; i < m; i++) {
      int customer_wealth = 0;
      std::vector<int> account = accounts[i];
      int n = account.size();
      for (int j = 0; j < n; j++) {
        customer_wealth += account[j];
      }
      max_wealth = std::max(customer_wealth, max_wealth);
    }
    return max_wealth;
  }
};
// @lc code=end
