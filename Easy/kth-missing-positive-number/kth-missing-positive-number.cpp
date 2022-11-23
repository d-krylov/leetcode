class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    int left = 0;
    int right = arr.size();
    int mid;
    int skipped;
    while (left < right) {
      mid = (left + right) >> 1;
      skipped = arr[mid] - mid - 1;
      if (skipped >= k) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left + k;
  }
};