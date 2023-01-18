class Solution {
public:
  vector<int> goodIndices(vector<int> &nums, int k) {
    auto n = nums.size();
    vector<int> ret;
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    for (int i = 1; i < n; i++) {
      if (nums[i] <= nums[i - 1]) {
        dec[i] = dec[i - 1] + 1;
      }
      if (nums[n - 1 - i] <= nums[n - i]) {
        inc[n - 1 - i] = inc[n - i] + 1;
      }
    }
    for (int i = k; i < n - k; i++) {
      if (inc[i + 1] >= k && dec[i - 1] >= k) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};