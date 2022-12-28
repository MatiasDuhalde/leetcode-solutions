#include <string>
#include <unordered_map>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> charmap;

    int max_size = 0;
    int current_substring_start = 0;
    int l = s.length();

    int word_size;
    for (int i = 0; i < l; i++) {
      char ch = s[i];

      // If we've seen this character before, we need to check if it's in the
      // current substring.
      auto it = charmap.find(ch);
      if (it != charmap.end()) {
        // If its index is greater than the current start, then it's in the
        // current substring.
        if (it->second >= current_substring_start) {
          word_size = i - current_substring_start;
          if (max_size < word_size) {
            max_size = word_size;
          }
          current_substring_start = it->second + 1;
        }
      }
      charmap[ch] = i;
    }

    // If we've reached the end of the string, we check if the size of the
    // current substring is greater than the max size.
    word_size = l - current_substring_start;
    if (max_size < word_size) {
      max_size = word_size;
    }

    return max_size;
  }
};
