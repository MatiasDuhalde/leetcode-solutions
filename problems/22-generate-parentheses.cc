/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  std::unordered_map<int, std::vector<std::string>> memo;

 public:
  std::vector<std::string> generateParenthesis(int n) {
    if (memo.find(n) != memo.end()) {
      return memo[n];
    }
    if (n == 0) {
      return {""};
    }
    if (n == 1) {
      return {"()"};
    }
    std::vector<std::string> res;
    for (int i = 0; i < n; i++) {
      auto left = generateParenthesis(i);
      auto right = generateParenthesis(n - i - 1);
      for (auto& l : left) {
        for (auto& r : right) {
          res.push_back("(" + l + ")" + r);
        }
      }
    }
    memo[n] = res;
    return res;
  }
};
// @lc code=end
