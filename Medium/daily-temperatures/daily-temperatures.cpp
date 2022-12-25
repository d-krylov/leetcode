class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> s;
    auto n = temperatures.size();
    vector<int> ret(n, 0);
    int i = 0;
    while (i < n) {
      if (s.empty() || temperatures[s.top()] >= temperatures[i]) {
        s.push(i++);
      } else {
        if (!s.empty()) {
          auto m = s.top();
          s.pop();
          ret[m] = i - m;
        }
      }
    }
    return ret;
  }
};