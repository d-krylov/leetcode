class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int64_t ret = -10000;
    int64_t temp = 0;
    for (auto &x : nums) {
      temp += x;
      ret = max(ret, temp);
      if (temp < 0) {
        temp = 0;
      }
    }
    return ret;
  }
};
