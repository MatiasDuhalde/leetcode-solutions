/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
#include <string>

class Solution {
 public:
  bool isMatch(std::string s, std::string p) {    const int ns = s.size();
    const int np = p.size();
    int last_star_index = -1;
    int last_match_index = -1;
    int i = 0;  // index of s
    int j = 0;  // index of p
    while (i < ns) {
      if (j < np && (p[j] == '?' || s[i] == p[j])) {
        i++;
        j++;
      } else if (j < np && p[j] == '*') {
        while (j < np && p[j] == '*') {
          j++;
        }
        last_star_index = j - 1;
        last_match_index = i;
      } else if (last_star_index != -1) {
        j = last_star_index + 1;
        last_match_index++;
        i = last_match_index;
      } else {
        return false;
      }
    }
    while (j < np && p[j] == '*') {
      j++;
    }
    return !(i < ns || j < np);
  }
};
// @lc code=end
