/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start

#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    int i = digits.size() - 1;
    while (i >= 0) {
      int value = digits[i];
      if (value == 9) {
        digits[i] = 0;
      } else {
        digits[i]++;
        break;
      }
      i--;
    }
    if (i == -1) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};
// @lc code=end
