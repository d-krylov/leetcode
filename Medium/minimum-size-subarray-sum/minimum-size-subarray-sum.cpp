class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0;
    int right = 0;
    int n = nums.size();
    int ret = n;
    int sum = 0;
    int current = 0;
    while (right < n) {
      current += nums[right++];
      while (current >= target && left <= right) {
        ret = min(ret, right - left);
        sum = current;
        current -= nums[left++];
      }
    }
    return sum >= target ? ret : 0;
  }
};