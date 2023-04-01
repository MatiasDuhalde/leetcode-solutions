/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>

class Solution {
 private:
  std::vector<std::vector<int>> recursivePart(std::vector<int>::iterator begin,
                                              std::vector<int>::iterator end,
                                              int target) {
    if (target == 0) {
      return {{}};
    }
    if (begin == end || target < 0) {
      return {};
    }

    // skip to next
    std::vector<std::vector<int>> a = recursivePart(begin + 1, end, target);

    std::vector<std::vector<int>> result = a;

    // add current and keep current
    std::vector<std::vector<int>> b =
        recursivePart(begin, end, target - *begin);

    for (auto& v : b) {
      v.push_back(*begin);
      result.push_back(v);
    }

    return result;
  }

 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                               int target) {
    return recursivePart(candidates.begin(), candidates.end(), target);
  }
};// @lc code=end
