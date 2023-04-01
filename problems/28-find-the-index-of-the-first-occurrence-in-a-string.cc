/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find The Index Of The First Occurrence In A String
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  int strStr(std::string haystack, std::string needle) {
    int l_h = haystack.length();
    int l_n = needle.length();
    if (l_h < l_n) return -1;

    std::vector<int> table(l_n);
    table[0] = -1;
    int pos = 1;
    int cnd = 0;
    while (pos < l_n) {
      if (needle[pos] == needle[cnd]) {
        table[pos] = table[cnd];
      } else {
        table[pos] = cnd;
        while (cnd >= 0 && needle[pos] != needle[cnd]) {
          cnd = table[cnd];
        }
      }
      pos++;
      cnd++;
    }

    int j = 0;
    int k = 0;
    while (j < l_h) {
      if (haystack[j] == needle[k]) {
        j++;
        k++;
        if (k == l_n) {
          return j - k;
        }
      } else {
        k = table[k];
        if (k < 0) {
          j++;
          k++;
        }
      }
    }

    return -1;
  }
};
// @lc code=end
