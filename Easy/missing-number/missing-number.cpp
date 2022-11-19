class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int s = 0;
    int n = nums.size();
    for (auto x : nums) {
      s += x;
    }
    return (n * (n + 1) >> 1) - s;
  }
};
