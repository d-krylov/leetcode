class Solution {
public:
  int findMin(vector<int> &nums) {
    auto left = 0;
    auto right = nums.size() - 1;
    int mid;
    while (left < right) {
      mid = (left + right) >> 1;
      if (nums[mid] < nums[right]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return nums[left];
  }
};