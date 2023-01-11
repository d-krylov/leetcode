class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    auto n = nums.size();
    vector<vector<int>> ret;
    if (n < 4)
      return ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < n - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int left = j + 1;
        int right = n - 1;
        while (left < right) {
          int64_t x = nums[left] + nums[right];
          int64_t y = static_cast<int64_t>(target) - nums[i] - nums[j];
          if (left > j + 1 && nums[left] == nums[left - 1]) {
            left++;
          } else if (right < n - 1 && nums[right] == nums[right + 1]) {
            right--;
          } else if (x < y) {
            left++;
          } else if (x > y) {
            right--;
          } else {
            ret.push_back({nums[i], nums[j], nums[left], nums[right]});
            left++;
            right--;
          }
        }
      }
    }
    return ret;
  }
};