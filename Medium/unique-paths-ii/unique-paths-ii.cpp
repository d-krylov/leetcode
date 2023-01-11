class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    auto m = obstacleGrid.size();
    auto n = obstacleGrid[0].size();
    int f = 1;

    if (obstacleGrid[0][0] == 1) {
      return 0;
    }

    for (int i = 0; i < n; i++) {
      if (obstacleGrid[0][i] == 1) {
        f = 0;
      }
      obstacleGrid[0][i] = f;
    }
    f = 1;
    for (int i = 1; i < m; i++) {
      if (obstacleGrid[i][0] == 1) {
        f = 0;
      }
      obstacleGrid[i][0] = f;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] == 1) {
          obstacleGrid[i][j] = 0;
          continue;
        }
        obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
      }
    }
    return obstacleGrid[m - 1][n - 1];
  }
};