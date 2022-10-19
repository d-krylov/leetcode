class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    auto n = nums.size();
    vector<vector<int>> ret(1 << n);
    int cnt;
    int tmp;
    for (int i = 0; i < 1 << n; i++) {
      cnt = n - 1;
      tmp = i;
      while (cnt >= 0) {
        if (tmp % 2 == 1) {
          ret[i].push_back(nums[cnt]);
        }
        tmp >>= 1;
        cnt--;
      }
    }
    return ret;
  }
};
