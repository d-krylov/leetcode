class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    auto n = triangle.size();
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i + 1; j++) {
        auto left = (j == 0) ? INT_MAX : triangle[i - 1][j - 1];
        auto right = (j == i) ? INT_MAX : triangle[i - 1][j];
        triangle[i][j] = min(left, right) + triangle[i][j];
      }
    }
    return *min_element(triangle.back().begin(), triangle.back().end());
  }
};