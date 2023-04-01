/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <string>

class Solution {
 public:
  int longestValidParentheses(std::string s) {
    int s_length = s.size();
    // Trim ')' from the left and '(' from the right
    int l = 0;
    int r = s_length - 1;
    while (l < r) {
      if (s[l] == ')') {
        l++;
      } else if (s[r] == '(') {
        r--;
      } else {
        break;
      }
    }
    // Set s to be the trimmed string
    s = s.substr(l, r - l + 1);
    s_length = s.size();
    int balance = 0;
    int i = 0;
    int reached_zero_max_index = -1;
    while (balance >= 0 && i < s_length) {
      if (s[i] == '(') {
        balance++;
      } else if (s[i] == ')') {
        balance--;
      }
      if (balance == 0) {
        reached_zero_max_index = i;
      }
      i++;
    }
    if (balance == 0) {
      return s_length;
    } else if (balance < 0) {
      int current_longest = i - 1;
      int remaining_length = s_length - i;
      if (current_longest <= remaining_length) {
        std::string remaining = s.substr(i);
        int substring_length = longestValidParentheses(remaining);
        current_longest = std::max(current_longest, substring_length);
      }
      return current_longest;
    }
    // balance is positive
    if (reached_zero_max_index > 0) {
      int current_longest = reached_zero_max_index + 1;
      int remaining_after_zero = s_length - reached_zero_max_index - 1;
      if (current_longest <= remaining_after_zero) {
        std::string remaining = s.substr(reached_zero_max_index + 1);
        int substring_length = longestValidParentheses(remaining);
        current_longest = std::max(current_longest, substring_length);
      }
      return current_longest;
    }
    // Terrible performance
    return longestValidParentheses(s.substr(balance));
  }
};
// @lc code=end
