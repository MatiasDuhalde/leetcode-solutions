/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
#include <climits>
#include <cmath>

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (divisor == INT_MIN) {
      return dividend == INT_MIN ? 1 : 0;
    }

    if (dividend == INT_MIN) {
      if (divisor == -1) {
        return INT_MAX;
      }
      if (divisor > 0) {
        return divide(dividend + divisor, divisor) - 1;
      } else if (divisor < 0) {
        return divide(dividend - divisor, divisor) + 1;
      }
    }

    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

    int remainder = dividend > 0 ? dividend : -dividend;
    int quotient = 0;
    divisor = divisor > 0 ? divisor : -divisor;
    while (remainder >= divisor) {
      int shift = 0;
      while ((divisor << shift) <= remainder && (divisor << shift) > 0) {
        ++shift;
      }
      --shift;
      quotient += (1 << shift);
      remainder -= (divisor << shift);
    }
    return sign > 0 ? quotient : -quotient;
  }
};// @lc code=end
