#include <climits>
#include <cmath>
#include <vector>

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    int l1 = nums1.size();
    int l2 = nums2.size();
    if (l2 < l1) {
      std::swap(nums1, nums2);
      std::swap(l1, l2);
    }
    if (l1 == 0) {
      if (l2 == 0) {
        return 0;
      }
      if (l2 % 2 == 0) {
        return (nums2[l2 / 2 - 1] + nums2[l2 / 2]) / 2.0;
      } else {
        return nums2[l2 / 2];
      }
    }
    int i;
    int j;
    int a_left;
    int a_right;
    int b_left;
    int b_right;
    int total = l1 + l2;
    int half = total / 2;
    int left = 0;
    int right = l1 - 1;
    while (true) {
      i = std::floor((left + right) / 2.0);
      j = half - i - 2;
      a_left = i < 0 ? INT_MIN : nums1[i];
      a_right = i + 1 >= l1 ? INT_MAX : nums1[i + 1];
      b_left = j < 0 ? INT_MIN : nums2[j];
      b_right = j + 1 >= l2 ? INT_MAX : nums2[j + 1];

      if (a_left <= b_right && b_left <= a_right) {
        break;
      } else if (a_left > b_right) {
        right = i - 1;
      } else {
        left = i + 1;
      }
    }
    if (total % 2 == 0) {
      return (std::max(a_left, b_left) + std::min(a_right, b_right)) / 2.0;
    } else {
      return std::min(a_right, b_right);
    }
  }
};