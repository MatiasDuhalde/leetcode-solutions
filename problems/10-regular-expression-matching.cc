/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include <string>

class Solution {
 public:
  bool isMatch(std::string s, std::string p) {
    int length_s = s.length();
    int length_p = p.length();

    // Base cases
    if (length_p == 0) {
      return length_s == 0;
    }
    if (length_p == 1) {
      return length_s == 1 && (s[0] == p[0] || p[0] == '.');
    }

    char current_matcher = p[0];
    char next_matcher = p[1];
    if (next_matcher != '*') {
      if (length_s == 0) {
        return false;
      }
      if (current_matcher == '.') {
        return isMatch(s.substr(1), p.substr(1));
      }
      return s[0] == current_matcher && isMatch(s.substr(1), p.substr(1));
    }
    if (current_matcher == '.') {
      for (int i = 0; i <= length_s; i++) {
        if (isMatch(s.substr(i), p.substr(2))) {
          return true;
        }
      }
      return false;
    }

    int i = 0;
    while (i < length_s && s[i] == current_matcher) {
      if (isMatch(s.substr(i + 1), p.substr(2))) {
        return true;
      }
      i++;
    }
    return isMatch(s, p.substr(2));
  }
};
// @lc code=end
