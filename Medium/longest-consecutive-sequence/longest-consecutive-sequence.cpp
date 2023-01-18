class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    unordered_set<int> s(nums.begin(), nums.end());
    int ret = 0;
    for (int x : s) {
      if (s.find(x - 1) == s.end()) {
        int current_x = x;
        int current_ret = 1;
        while (s.find(current_x + 1) != s.end()) {
          current_x++;
          current_ret++;
        }
        ret = max(ret, current_ret);
      }
    }
    return ret;
  }
};