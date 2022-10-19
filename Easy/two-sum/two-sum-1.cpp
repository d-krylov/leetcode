class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      auto x = m.find(target - nums[i]);
      if (x != m.end()) {
        return {x->second, i};
      }
      m.insert({nums[i], i});
    }
    return {0, 0};
  }
};
