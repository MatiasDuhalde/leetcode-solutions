/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution {
 public:
  double myPow(double x, int n) {
    if (x == 1 || n == 0) {
      return 1;
    }
    if (x == -1) {
      if (n % 2 == 0) {
        return 1;
      }
      return -1;
    }
    if (n == INT_MIN) {
      return 0;
    }
    if (n < 0) {
      x = 1 / x;
      n = -n;
    }
    double res = x;
    for (int i = 1; i < n; i++) {
      res *= x;
    }
    return res;
  }
};
// @lc code=end
