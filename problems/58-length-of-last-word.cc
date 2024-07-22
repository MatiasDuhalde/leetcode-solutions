/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <string>

class Solution {
public:
  int lengthOfLastWord(std::string s) {
    int i = s.size() - 1;
    int lastSize = 0;
    while (i >= 0) {
      if (s[i] != ' ') {
        lastSize++;
      } else if (lastSize != 0) {
        break;
      }
      i--;
    }
    return lastSize;
  }
};
// @lc code=end
