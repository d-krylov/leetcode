class Solution {
public:
  void combinationSum(int target, int d, vector<int> &c,
                      vector<vector<int>> &ret, vector<int> &v) {
    if (target == 0) {
      ret.push_back(v);
      return;
    }
    for (int i = d; i < c.size(); i++) {
      if (i > d && c[i] == c[i - 1]) {
        continue;
      }
      if (c[i] > target) {
        break;
      }
      v.push_back(c[i]);
      combinationSum(target - c[i], i + 1, c, ret, v);
      v.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ret;
    vector<int> v;
    combinationSum(target, 0, candidates, ret, v);
    return ret;
  }
};