class Solution {
public:
  bool search(vector<int> &nums, int target) {
    auto n = nums.size();
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
      mid = (left + right) >> 1;
      if (nums[mid] == target) {
        return true;
      }
      if (nums[mid] > nums[left]) {
        if (nums[mid] > target && nums[left] <= target) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else if (nums[mid] < nums[left]) {
        if (nums[mid] < target && nums[right] >= target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {
        left++;
      }
    }
    return false;
  }
};