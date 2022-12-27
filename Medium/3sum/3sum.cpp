class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    int a, b, c;
    int start, end;
    for (int i = 0; i < nums.size() - 2; i++) {
      a = nums[i];
      start = i + 1;
      end = nums.size() - 1;
      while (start < end) {
        b = nums[start];
        c = nums[end];
        if (a + b + c == 0) {
          ret.emplace_back(vector{a, b, c});
          start++;
          end--;
        } else if (a + b + c > 0) {
          end--;
        } else {
          start++;
        }
      }
    }
    set<vector<int>> int_set(ret.begin(), ret.end());
    ret.assign(int_set.begin(), int_set.end());
    return ret;
  }
};