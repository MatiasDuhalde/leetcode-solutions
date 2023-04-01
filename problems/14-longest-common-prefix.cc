/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <climits>
#include <string>
#include <vector>

class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    int size = strs.size();

    // Find the size of the shortest string.
    int min_length = INT_MAX;
    for (int i = 0; i < size; i++) {
      int length = strs[i].length();
      if (length < min_length) {
        min_length = length;
      }
    }

    std::string current_prefix = "";
    for (int i = 0; i < min_length; i++) {
      char current_char = strs[0][i];
      for (int j = 1; j < size; j++) {
        if (strs[j][i] != current_char) {
          return current_prefix;
        }
      }
      current_prefix += current_char;
    }

    return current_prefix;
  }
};
// @lc code=end
