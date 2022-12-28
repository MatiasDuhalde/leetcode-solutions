#include <vector>

class Solution {
 public:
  std::vector<int> runningSum(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> v(size);
    v[0] = nums[0];
    for (int i = 1; i < size; i++) {
      v[i] = nums[i] + v[i - 1];
    }
    return v;
  }
};
