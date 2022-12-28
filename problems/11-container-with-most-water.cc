#include <vector>

class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int max_area = 0;
    while (i < j) {
      int area;
      if (height[i] < height[j]) {
        area = height[i] * (j - i);
        i++;
      } else {
        area = height[j] * (j - i);
        j--;
      }
      if (area > max_area) {
        max_area = area;
      }
    }

    return max_area;
  }
};
