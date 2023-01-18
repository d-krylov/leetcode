class Solution {
public:
  int minimizeArrayValue(vector<int> &nums) {
    int64_t sum = 0;
    int64_t avg = 0;
    int64_t ret = 0;
    int cnt = 0;
    for (auto x : nums) {
      sum += x;
      avg = (sum + cnt) / (cnt + 1);
      ret = max(ret, avg);
      cnt++;
    }
    return ret;
  }
};