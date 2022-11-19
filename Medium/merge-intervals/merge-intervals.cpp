class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vector<vector<int>> ret;
    sort(intervals.begin(), intervals.end());
    for (auto in : intervals) {
      if (ret.empty() || in[0] > ret.back()[1]) {
        ret.push_back(in);
      } else {
        if (in[1] > ret.back()[1]) {
          ret.back()[1] = in[1];
        }
      }
    }
    return ret;
  }
};
