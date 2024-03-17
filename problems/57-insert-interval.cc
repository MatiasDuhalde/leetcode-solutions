/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
                                       std::vector<int> &newInterval) {
    std::vector<std::vector<int>> inserted;

    bool ins = false;
    int i = 0;
    while (i < intervals.size()) {
      if (newInterval[0] > intervals[i][1]) {
        // Interval is greater, goes after
        inserted.push_back(intervals[i]);
      } else if (newInterval[1] < intervals[i][0]) {
        // Interval is lesser, goes before
        if (!ins) {
          inserted.push_back(newInterval);
          ins = true;
        }
        inserted.push_back(intervals[i]);
      } else {
        // interval intersects, merge is in order
        if (newInterval[0] > intervals[i][0]) {
          newInterval[0] = intervals[i][0];
        }
        if (newInterval[1] < intervals[i][1]) {
          newInterval[1] = intervals[i][1];
        }
      }
      i++;
    }

    if (!ins) {
      inserted.push_back(newInterval);
    }

    return inserted;
  }
};
// @lc code=end
