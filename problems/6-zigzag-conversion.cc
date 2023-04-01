/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include <string>

class Solution {
 public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1) {  // Trivial case
      return s;
    }

    std::string output = "";
    int length = s.length();
    for (int current_row = 0; current_row < numRows; current_row++) {
      // Calculate offsets for each row
      int row_offset_1 = (numRows - current_row - 1) * 2;
      int row_offset_2 = current_row * 2;

      // Add corresponding characters to output
      for (int i = current_row; i < length;) {
        if (row_offset_1 != 0 && i < length) {
          output += s[i];
          i += row_offset_1;
        }
        if (row_offset_2 != 0 && i < length) {
          output += s[i];
          i += row_offset_2;
        }
      }
    }

    return output;
  }
};
// @lc code=end
