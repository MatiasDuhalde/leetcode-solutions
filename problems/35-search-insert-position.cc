#include <vector>

class Solution {
 public:
  int searchInsert(std::vector<int>& nums, int target) {
    int nums_length = nums.size();
    int l = 0;
    int r = nums_length - 1;
    while (l < r) {
      int current_middle = (l + r) / 2;
      int current_value = nums[current_middle % nums_length];
      if (current_value == target) {
        return current_middle;
      }
      if (target < current_value) {
        r = current_middle - 1;
      } else {
        l = current_middle + 1;
      }
    }
    if (target <= nums[l]) {
      return l;
    }
    return l + 1;
  }
};