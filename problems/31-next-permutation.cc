#include <algorithm>
#include <vector>

class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    // Find length
    int length = nums.size();
    if (length < 2) {
      return;
    }
    if (length == 2) {
      std::swap(nums[0], nums[1]);
      return;
    }

    // Find largest index k such that nums[k] < nums[k + 1]
    int k = length - 2;
    bool found_k = false;
    while (0 <= k) {
      if (nums[k] < nums[k + 1]) {
        found_k = true;
        break;
      }
      k--;
    }
    if (!found_k) {
      // If no k is found, the list is in its last permutation state
      std::reverse(nums.begin(), nums.end());
      return;
    }
    // Find the largest index l greater than k such that nums[k] < nums[l]
    int l = length - 1;
    while (k < l) {
      if (nums[k] < nums[l]) {
        break;
      }
      l--;
    }
    std::swap(nums[k], nums[l]);
    std::reverse(nums.begin() + k + 1, nums.end());
  }
};
