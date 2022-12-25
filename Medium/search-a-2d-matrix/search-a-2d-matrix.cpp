class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    auto m = matrix.size();
    auto n = matrix[0].size();
    int start = 0;
    int end = m * n - 1;
    int mid;
    while (start < end) {
      mid = (start + end) >> 1;
      auto x = matrix[mid / n][mid % n];
      if (x > target) {
        end = mid;
      } else if (x < target) {
        start = mid + 1;
      } else {
        return true;
      }
    }
    return matrix[start / n][start % n] == target;
  }
};