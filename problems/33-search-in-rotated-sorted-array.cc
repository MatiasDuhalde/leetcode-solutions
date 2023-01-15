#include <vector>

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    int nums_length = nums.size();
    int offset = 0;
    int l = 0;
    int r = nums_length - 1;
    if (nums[l] > nums[r]) {
      // find position of the minimum value
      int current_middle = 0;
      while (r - l > 1) {
        current_middle = (l + r) / 2;
        int current_value = nums[current_middle];
        if (current_value < nums[l]) {
          r = current_middle;
        } else {
          l = current_middle;
        }
      }
      offset = nums[r] < nums[l] ? r : l;
    }

    l = offset;
    r = nums_length + offset - 1;
    while (l < r) {
      int current_middle = (l + r) / 2;
      int current_value = nums[current_middle % nums_length];
      if (current_value == target) {
        return current_middle % nums_length;
      }
      if (target < current_value) {
        r = current_middle - 1;
      } else {
        l = current_middle + 1;
      }
    }
    if (nums[l % nums_length] == target) {
      return l % nums_length;
    }
    return -1;
  }
};
