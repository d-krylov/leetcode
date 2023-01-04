class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int insert = n + m - 1;
    int up = m - 1;
    int down = n - 1;
    while (down >= 0 && up >= 0) {
      if (nums1[up] > nums2[down]) {
        nums1[insert--] = nums1[up--];
      } else {
        nums1[insert--] = nums2[down--];
      }
    }
    while (up >= 0) {
      nums1[insert--] = nums1[up--];
    }
    while (down >= 0) {
      nums1[insert--] = nums2[down--];
    }
  }
};