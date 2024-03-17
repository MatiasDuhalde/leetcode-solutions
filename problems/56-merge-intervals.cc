/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> merged;
    std::sort(
        intervals.begin(), intervals.end(),
        [](std::vector<int> &a, std::vector<int> &b) { return a[0] < b[0]; });

    int currentStart = intervals[0][0];
    int currentEnd = intervals[0][1];
    int i = 1;
    while (i < intervals.size()) {
      if (intervals[i][0] <= currentEnd) {
        if (intervals[i][1] > currentEnd) {
          currentEnd = intervals[i][1];
        }
      } else {
        merged.push_back({currentStart, currentEnd});
        currentStart = intervals[i][0];
        currentEnd = intervals[i][1];
      }
      i++;
    }
    merged.push_back({currentStart, currentEnd});

    return merged;
  }
};
// @lc code=end
