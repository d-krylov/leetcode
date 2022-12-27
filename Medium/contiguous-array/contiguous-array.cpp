class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    unordered_map<int, int> m = {{0, -1}};
    int cnt = 0;
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      cnt += 2 * nums[i] - 1;
      if (m.find(cnt) != m.end()) {
        ret = max(ret, i - m[cnt]);
      } else {
        m[cnt] = i;
      }
    }
    return ret;
  }
};