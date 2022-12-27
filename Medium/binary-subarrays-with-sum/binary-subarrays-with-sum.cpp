class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    unordered_map<int, int> m = {{0, 1}};
    int cnt = 0;
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      cnt += nums[i];
      if (m.find(cnt - goal) != m.end()) {
        ret += m[cnt - goal];
      }
      m[cnt]++;
    }
    return ret;
  }
};