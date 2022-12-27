class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    int64_t sum = 0;
    unordered_map<int, int> m = {{0, -1}};
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      sum %= k;
      if (m.find(sum) != m.end()) {
        if (i - m[sum] > 1)
          return true;
      } else {
        m[sum] = i;
      }
    }
    return false;
  }
};