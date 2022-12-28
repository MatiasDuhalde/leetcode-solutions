#include <string>
#include <unordered_map>

class Solution {
 public:
  std::unordered_map<char, int> buildMap(std::string str) {
    std::unordered_map<char, int> mp;
    char ch;
    int n = str.length();
    for (int i = 0; i < n; i++) {
      ch = str[i];
      if (mp.find(ch) != mp.end())
        mp[ch]++;
      else
        mp[ch] = 1;
    }
    return mp;
  }

  bool canConstruct(std::string ransomNote, std::string magazine) {
    char ch;
    std::unordered_map<char, int>::const_iterator it;
    std::unordered_map<char, int> magazine_map = buildMap(magazine);
    int n = ransomNote.length();
    for (int i = 0; i < n; i++) {
      ch = ransomNote[i];
      it = magazine_map.find(ch);
      if (it != magazine_map.end() && it->second > 0)
        magazine_map[ch]--;
      else
        return false;
    }
    return true;
  }
};
