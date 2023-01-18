class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    auto n = nums.size();
    int position = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i] != nums[position]) {
        nums[++position] = nums[i];
      }
    }
    return position + 1;
  }
};
