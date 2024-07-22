/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start

#include <string>

class Solution {
public:
  std::string getPermutation(int n, int k) {
    int fact = 1;
    for (int i = 2; i < n; i++) {
      fact *= i;
    }
    std::string res = "";

    for (int i = 0; i < n; i++) {

      int digit = ((k - 1) / fact + 1 % 4 + (i - 1)) % 4 + 1;

      res += std::to_string(digit);

      if (i < n - 1) {
        fact /= (n - i - 1);
      }
    }

    return res;
  }
};
// @lc code=end
