#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> result;

    int size = nums.size();
    for (int i = 0; i < size;) {
      int a = nums[i];

      // If the current number is the same as the previous one, skip it.
      if (i > 0 && a == nums[i - 1]) {
        continue;
      }

      for (int j = i + 1; j < size;) {
        int b = nums[j];
        long sum_a_b = a + b;

        int left = j + 1;
        int right = size - 1;
        while (left < right) {
          int c = nums[left];
          int d = nums[right];
          long sum = sum_a_b + c + d;
          if (target == sum) {
            result.push_back({a, b, c, d});

            while (left < right && nums[left] == c) {
              left++;
            }
            while (left < right && nums[right] == d) {
              right--;
            }
          } else if (sum < target) {
            while (left < right && nums[left] == c) {
              left++;
            }
          } else {
            while (left < right && nums[right] == d) {
              right--;
            }
          }
        }
        while (j < size && nums[j] == b) {
          j++;
        }
      }
      while (i < size && nums[i] == a) {
        i++;
      }
    }
    return result;
  }
};
