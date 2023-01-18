class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    auto m = grid.size();
    auto n = grid[0].size();
    int sum = 0;
    int P[m][n];
    P[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
      P[i][0] = P[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++) {
      P[0][i] = P[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        P[i][j] = min(P[i - 1][j], P[i][j - 1]) + grid[i][j];
      }
    }
    return P[m - 1][n - 1];
  }
};
