/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <list>
#include <string>
#include <unordered_map>

class Solution {
 public:
  bool isPalindrome(std::string s) {
    int length = s.length();
    int l = 0;
    int r = length - 1;
    for (l = 0; l < r; l++) {
      if (s[l] != s[r]) {
        return false;
      }
      r--;
    }
    return true;
  }

  std::string longestPalindrome(std::string s) {
    int length = s.length();

    // Get locations of each character.
    std::unordered_map<char, std::list<int>> charmap;
    for (int i = 0; i < length; i++) {
      charmap[s[i]].push_back(i);
    }

    auto ch_begin = charmap.begin();
    auto ch_end = charmap.end();

    int max_length = 1;
    std::string max_substring = s.substr(0, 1);
    std::string current_substring;

    for (auto it_char = ch_begin; it_char != ch_end; it_char++) {
      std::list<int> index_list = it_char->second;
      auto list_begin = index_list.begin();
      auto list_end = index_list.end();

      for (auto it_pos_1 = list_begin; it_pos_1 != list_end; it_pos_1++) {
        int current_start_index = *it_pos_1;
        if (length - current_start_index <= max_length) {
          break;
        }

        for (auto it_pos_2 = list_end; it_pos_2 != it_pos_1;) {
          it_pos_2--;
          int current_end_index = *it_pos_2;
          int current_length = current_end_index - current_start_index + 1;
          if (current_length <= max_length) {
            break;
          }

          current_substring = s.substr(current_start_index, current_length);
          if (isPalindrome(current_substring)) {
            if (current_length > max_length) {
              max_length = current_length;
              max_substring = current_substring;
            }
          }
        }
      }
    }
    return max_substring;
  }
};
// @lc code=end
