#include <string>

class Solution {
 public:
  std::string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }
    std::string result = "";
    std::string prev = countAndSay(n - 1);
    int current_count = 1;
    char current_char = prev[0];
    int prev_length = prev.length();
    for (int i = 1; i < prev_length; i++) {
      if (prev[i] == current_char) {
        current_count++;
      } else {
        result += std::to_string(current_count) + current_char;
        current_count = 1;
        current_char = prev[i];
      }
    }
    result += std::to_string(current_count) + current_char;
    return result;
  }
};
