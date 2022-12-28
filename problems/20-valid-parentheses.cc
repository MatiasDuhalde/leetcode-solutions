#include <list>
#include <string>

class Solution {
 public:
  bool isValid(std::string s) {
    std::list<char> stack;
    for (char& ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        stack.push_back(ch);
      } else {
        if (stack.size() == 0) {
          return false;
        }
        char last_ch = stack.back();
        if ((ch == ')' && last_ch == '(') || (ch == ']' && last_ch == '[') ||
            (ch == '}' && last_ch == '{')) {
          stack.pop_back();
        } else {
          return false;
        }
      }
    }
    return stack.size() == 0;
  }
};
