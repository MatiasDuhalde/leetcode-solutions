#include <algorithm>
#include <vector>

class Solution {
 private:
  void recursivePart(std::vector<int>& candidates, int index, int target,
                     std::vector<int>& local,
                     std::vector<std::vector<int>>& res) {
    if (target == 0) {
      res.push_back(local);
      return;
    } else {
      int h = candidates.size();
      for (int i = index; i < h; i++) {
        int current_value = candidates[i];
        if (current_value > target) {
          return;
        }
        if (i > 0 && current_value == candidates[i - 1] && i > index) continue;
        local.push_back(current_value);
        recursivePart(candidates, i + 1, target - current_value, local, res);
        local.pop_back();
      }
    }
  }

 public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates,
                                                int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> result;
    std::vector<int> local;
    recursivePart(candidates, 0, target, local, result);
    return result;
  }
};
