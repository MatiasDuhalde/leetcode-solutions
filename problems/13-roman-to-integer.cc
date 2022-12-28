#include <string>

class Solution {
 public:
  int romanToInt(std::string s) {
    int result = 0;
    char previous_char = ' ';
    for (int i = s.length() - 1; i >= 0; i--) {
      char current_char = s[i];
      if (current_char == 'I') {
        if (previous_char == 'V' || previous_char == 'X') {
          result -= 1;
        } else {
          result += 1;
        }
      } else if (current_char == 'V') {
        result += 5;
      } else if (current_char == 'X') {
        if (previous_char == 'L' || previous_char == 'C') {
          result -= 10;
        } else {
          result += 10;
        }
      } else if (current_char == 'L') {
        result += 50;
      } else if (current_char == 'C') {
        if (previous_char == 'D' || previous_char == 'M') {
          result -= 100;
        } else {
          result += 100;
        }
      } else if (current_char == 'D') {
        result += 500;
      } else if (current_char == 'M') {
        result += 1000;
      }
      previous_char = current_char;
    }

    return result;
  }
};
