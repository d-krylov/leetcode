class Solution {
public:
  static bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
      return p1.first > p2.first;
    }
    return p1.second > p2.second;
  }

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (auto x : nums) {
      m[x]++;
    }
    vector<pair<int, int>> f(m.begin(), m.end());
    sort(f.begin(), f.end(), compare);
    vector<int> ret(k, 0);
    for (int i = 0; i < k; i++) {
      ret[i] = f[i].first;
    }
    return ret;
  }
};