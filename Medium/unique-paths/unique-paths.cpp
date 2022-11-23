class Solution {
public:
  int uniquePaths(int m, int n) {
    uint64_t P[m][n];

    for (int i = 0; i < m; i++) {
      P[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
      P[0][i] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        P[i][j] = P[i - 1][j] + P[i][j - 1];
      }
    }

    return P[m - 1][n - 1];
  }
};