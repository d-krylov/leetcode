class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    auto left = 0;
    auto right = n - 1;
    int mid;
    while (left < right) {
      mid = (left + right) >> 1;
      if (nums[mid] < nums[right]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    right = n - 1;
    int pivot = left;
    left = 0;
    while (right >= left) {
      mid = (left + right) >> 1;
      int rotation = (mid + pivot) % n;
      if (nums[rotation] == target)
        return rotation;
      if (target > nums[rotation])
        left = mid + 1;
      else
        right = mid - 1;
    }
    return -1;
  }
};