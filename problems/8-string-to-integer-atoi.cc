#include <climits>
#include <string>

class Solution {
 public:
  int myAtoi(std::string s) {
    bool found_number = false;
    int length = s.length();
    int output = 0;
    int factor = 1;

    for (int i = 0; i < length; i++) {
      char ch = s[i];
      int digit = s[i] - '0';
      if (ch == ' ') {
        if (found_number) {
          // If whitespace is found after the start of a number, always return.
          return output;
        }
      } else if (ch == '+' || ch == '-') {
        if (found_number) {
          // If a +/- sign is found after the start of a number, always return.
          return output;
        }
        if (ch == '-') {
          factor = -1;
        }
        // A +/- sign marks the start of a number.
        found_number = true;
      } else if (digit <= 9 && digit >= 0) {
        // If character is a number, add it to the output.
        found_number = true;
        if (output > INT_MAX / 10 || (output == INT_MAX / 10 && digit > 7)) {
          return INT_MAX;
        }
        if (output < INT_MIN / 10 || (output == INT_MIN / 10 && digit > 8)) {
          return INT_MIN;
        }
        output = output * 10 + digit * factor;
      } else {
        // If character is not a number, whitespace, or +/- sign, always return.
        return output;
      }
    }
    return output;
  }
};
