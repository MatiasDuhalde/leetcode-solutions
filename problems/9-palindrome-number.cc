#include <cmath>

class Solution {
 public:
  bool isPalindrome(int x) {
    // Negative numbers are not palindromes (- sign is not at the end).
    if (x < 0) {
      return false;
    }

    // Calculate the length of the number.
    int length = 0;
    int temp = x;
    while (temp != 0) {
      temp /= 10;
      length++;
    }

    // Compare corresponding digits.
    int left = 0;
    int right = length - 1;
    while (left < right) {
      int pow_left = std::pow(10, left);
      int pow_right = std::pow(10, right);
      int left_digit = (x / pow_left) % 10;
      int right_digit = (x / pow_right) % 10;
      if (left_digit != right_digit) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
};