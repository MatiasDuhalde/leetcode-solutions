#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 private:
  static const std::unordered_map<char, std::string> phoneMap() {
    static const auto phoneMap = new std::unordered_map<char, std::string>{
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    return *phoneMap;
  };

 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) {
      return {};
    }

    auto phone_map = phoneMap();
    std::vector<std::string> result = {""};
    for (char& ch : digits) {
      std::string letters = phone_map.find(ch)->second;

      std::vector<std::string> new_result;
      for (std::string& possibility : result) {
        for (char& letter : letters) {
          new_result.push_back(possibility + letter);
        }
      }
      result = new_result;
    }

    return result;
  }
};
