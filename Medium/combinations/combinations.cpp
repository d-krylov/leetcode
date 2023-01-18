class Solution {
public:
  void combine(int n, int k, int d, vector<int> &v, vector<vector<int>> &ret) {
    if (k == 0) {
      ret.push_back(v);
      return;
    }
    for (int i = d; i <= n; i++) {
      v.push_back(i);
      combine(n, k - 1, i + 1, v, ret);
      v.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> v;
    combine(n, k, 1, v, ret);
    return ret;
  }
};