class Solution {
public:
  void NextPermutation(vector<int> &nums) {
    auto n = nums.size();
    int i = n - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
      i--;
    }
    if (i >= 0) {
      int j = n - 1;
      while (nums[j] <= nums[i]) {
        j--;
      }
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }

  int64_t factorial(int n) {
    long f = 1;
    for (int i = 1; i <= n; ++i)
      f *= i;
    return f;
  }

  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ret;
    auto n = factorial(nums.size());
    ret.reserve(n);
    for (int i = 0; i < n; i++) {
      ret.push_back(nums);
      NextPermutation(nums);
    }
    return ret;
  }
};
