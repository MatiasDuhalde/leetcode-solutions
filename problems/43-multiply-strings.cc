/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <string>

class Solution {
 public:
  std::string multiply(std::string num1, std::string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    // initialize zeroed array of size n1 + n2
    int* result = new int[n1 + n2]();
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        int val = (num1[n1 - i - 1] - '0') * (num2[n2 - j - 1] - '0');
        result[i + j] += val;
      }
    }
    for (int i = 0; i < n1 + n2 - 1; i++) {
      result[i + 1] += result[i] / 10;
      result[i] = result[i] % 10;
    }
    std::string res;
    for (int i = n1 + n2 - 1; i >= 0; i--) {
      if (res.empty() && result[i] == 0) {
        continue;
      }
      res += result[i] + '0';
    }
    if (res.empty()) {
      res = "0";
    }
    delete[] result;
    return res;
  }
};
// @lc code=end
