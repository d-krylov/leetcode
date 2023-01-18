class Solution {
public:
  int trap(vector<int> &height) {
    int ret = 0;
    auto n = height.size();
    int previous = height[0];
    int previous_index = 0;
    int temp = 0;
    for (int i = 1; i < n; i++) {
      if (height[i] >= previous) {
        previous = height[i];
        previous_index = i;
        temp = 0;
      } else {
        ret += previous - height[i];
        temp += previous - height[i];
      }
    }
    if (previous_index < n - 1) {
      ret -= temp;
      previous = height[n - 1];
      for (int i = n - 1; i >= previous_index; i--) {
        if (height[i] >= previous) {
          previous = height[i];
        } else {
          ret += previous - height[i];
        }
      }
    }
    return ret;
  }
};