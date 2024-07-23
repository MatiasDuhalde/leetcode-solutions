/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start

#include <string>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    bool carry = false;
    std::string result = "";
    int index_a = a.size() - 1;
    int index_b = b.size() - 1;
    while (index_a >= 0 && index_b >= 0) {
      char digit_a = a.at(index_a);
      char digit_b = b.at(index_b);
      if (digit_a == '0') {
        if (digit_b == '0') {
          result.insert(result.begin(), carry ? '1' : '0');
          carry = false;
        } else {
          result.insert(result.begin(), carry ? '0' : '1');
        }
      } else {
        if (digit_b == '0') {
          result.insert(result.begin(), carry ? '0' : '1');
        } else {
          result.insert(result.begin(), carry ? '1' : '0');
          carry = true;
        }
      }
      index_a--;
      index_b--;
    }
    while (index_a >= 0) {
      char digit_a = a.at(index_a);
      if (digit_a == '1') {
        result.insert(result.begin(), carry ? '0' : '1');
      } else {
        result.insert(result.begin(), carry ? '1' : '0');
        carry = false;
      }
      index_a--;
    }
    while (index_b >= 0) {
      char digit_b = b.at(index_b);
      if (digit_b == '1') {
        result.insert(result.begin(), carry ? '0' : '1');
      } else {
        result.insert(result.begin(), carry ? '1' : '0');
        carry = false;
      }
      index_b--;
    }
    if (carry) {
      result.insert(result.begin(), '1');
    }
    return result;
  }
};
// @lc code=end
