class Solution {
public:
  int search(vector<int> &nums, int target) {
    auto right = nums.size() - 1;
    int left = 0;
    if (right == 0)
      return (nums[0] == target) ? 0 : -1;
    int mid;
    while (left < right) {
      mid = (left + right) >> 1;
      if (nums[mid] > target) {
        right = mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        return mid;
      }
    }
    return nums[left] == target ? left : -1;
  }
};