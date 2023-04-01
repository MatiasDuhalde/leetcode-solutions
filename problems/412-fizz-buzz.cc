/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> result(n);
    for (int i = 1; i <= n; i++) {
      std::string res = "";
      if (i % 3 == 0) {
        res += "Fizz";
      }
      if (i % 5 == 0) {
        res += "Buzz";
      }
      if (res == "") {
        res += std::to_string(i);
      }
      result[i - 1] = res;
    }
    return result;
  }
};
// @lc code=end
