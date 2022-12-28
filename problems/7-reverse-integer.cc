#include <climits>

class Solution {
 public:
  int reverse(int x) {
    int output = 0;

    while (x != 0) {
      int current_digit = x % 10;
      if (output > INT_MAX / 10 ||
          (output == INT_MAX / 10 && current_digit > 7)) {
        return 0;
      }
      if (output < INT_MIN / 10 ||
          (output == INT_MIN / 10 && current_digit < -8)) {
        return 0;
      }
      output = output * 10 + current_digit;
      x /= 10;
    }

    return output;
  }
};
