class Solution {
public:
  int maxArea(vector<int> &h) {
    int right = h.size() - 1;
    int left = 0;
    int ret = 0;
    while (left < right) {
      auto V = (right - left) * min(h[right], h[left]);
      ret = max(ret, V);
      if (h[left] < h[right]) {
        left++;
      } else {
        right--;
      }
    }
    return ret;
  }
};