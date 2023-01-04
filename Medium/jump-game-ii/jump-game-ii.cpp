class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
      return 0;
    }
    int pos = 0;
    int cnt = 1;
    int new_pos = 0;
    for (int i = 0; i <= pos; i++) {
      new_pos = max(new_pos, nums[i] + i);
      if (new_pos >= n - 1) {
        break;
      }
      if (i == pos) {
        cnt++;
        pos = new_pos;
      }
    }
    return cnt;
  }
};