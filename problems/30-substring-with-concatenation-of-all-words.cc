/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring With Concatenation Of All Words
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string>& words) {
    std::vector<int> result;
    int l_s = s.size();
    int l_w = words.size();
    int word_size = words[0].size();
    int match_length = l_w * word_size;
    if (l_s < match_length) {
      return result;
    }
    std::unordered_map<std::string, int> word_count;
    for (auto& word : words) {
      word_count[word]++;
    }
    for (int i = 0; i < l_s - match_length + 1; ++i) {
      std::unordered_map<std::string, int> word_count_copy(word_count);
      int j = i;
      while (j < i + match_length) {
        std::string word = s.substr(j, word_size);
        if (word_count_copy.find(word) == word_count_copy.end()) {
          break;
        }
        word_count_copy[word]--;
        if (word_count_copy[word] == 0) {
          word_count_copy.erase(word);
        }
        j += word_size;
      }
      if (word_count_copy.empty()) {
        result.push_back(i);
      }
    }
    return result;
  }
};
// @lc code=end
