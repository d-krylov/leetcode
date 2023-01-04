class Solution {
public:
  int numTrees(int n) {
    vector<int64_t> d(n + 1, 0);
    d[0] = 1;
    d[1] = 1;
    for (int m = 2; m <= n; m++) {
      for (int j = 1; j <= m; j++) {
        d[m] += d[j - 1] * d[m - j];
      }
    }
    return d[n];
  }
};