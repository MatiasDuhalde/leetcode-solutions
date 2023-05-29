/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(
      std::vector<std::string>& strs) {
    int n = strs.size();
    std::unordered_map<std::string, std::vector<std::string>> anagrams_map;
    for (int i = 0; i < n; i++) {
      std::string s = strs[i];
      std::sort(s.begin(), s.end());
      anagrams_map[s].push_back(strs[i]);
    }

    std::vector<std::vector<std::string>> res;
    for (auto i : anagrams_map) {
      res.push_back(i.second);
    }

    return res;
  }
};
// @lc code=end
