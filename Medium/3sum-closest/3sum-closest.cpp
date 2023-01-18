class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    auto n = nums.size();
    int ret = nums[0] + nums[1] + nums[2];
    if (n == 3) {
      return ret;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        auto sum = nums[left] + nums[right] + nums[i];
        if (abs(sum - target) < abs(ret - target)) {
          ret = sum;
          if (sum == target) {
            return sum;
          }
        }
        if (sum > target) {
          right--;
        } else {
          left++;
        }
      }
    }
    return ret;
  }
};