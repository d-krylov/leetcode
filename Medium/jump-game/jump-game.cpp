class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums[0];
    if (nums.size() == 1)
      return true;
    for (int i = 0; i <= n; i++) {
      n = max(n, nums[i] + i);
      if (n >= nums.size() - 1) {
        return true;
      }
    }
    return false;
  }
};
