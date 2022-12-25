class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int total = 0;
    int current_max = 0;
    int current_min = 0;
    int result_min = nums[0];
    int result_max = nums[0];
    for (auto x : nums) {
      total += x;
      current_max = max(x, current_max + x);
      current_min = min(x, current_min + x);
      result_max = max(current_max, result_max);
      result_min = min(current_min, result_min);
    }
    return result_max > 0 ? max(result_max, total - result_min) : result_max;
  }
};