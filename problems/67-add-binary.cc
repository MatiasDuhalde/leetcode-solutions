/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start

#include <vector>

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int = digits.size();
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
    }
    return digits;
  }
};
// @lc code=end
