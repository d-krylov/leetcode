class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    int mid;
    while (left <= right) {
      mid = (left + right) >> 1;
      int val = nums[mid];

      if (val < target)
        left = mid + 1;
      else if (val > target)
        right = mid - 1;
      else
        return mid;
    }
    return left;
  }
};
