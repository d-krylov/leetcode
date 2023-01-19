class Solution {
public:
  vector<int> Compute(unordered_map<string, vector<int>> &m, string s) {
    if (m.find(s) != m.end()) {
      return m[s];
    }
    vector<int> ret;
    auto n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
        auto left = Compute(m, s.substr(0, i));
        auto right = Compute(m, s.substr(i + 1));
        for (auto lhs : left) {
          for (auto rhs : right) {
            if (s[i] == '+') {
              ret.push_back(lhs + rhs);
            } else if (s[i] == '-') {
              ret.push_back(lhs - rhs);
            } else {
              ret.push_back(lhs * rhs);
            }
          }
        }
      }
    }
    if (ret.empty()) {
      ret.push_back(stoi(s));
    }
    m[s] = ret;
    return ret;
  }

  vector<int> diffWaysToCompute(string expression) {
    unordered_map<string, vector<int>> m;
    return Compute(m, expression);
  }
};