class Solution {
public:
  bool IsValidString(string s) {
    int cnt = 0;
    for (auto x : s) {
      if (x == '(') {
        cnt++;
      } else if (x == ')') {
        cnt--;
      } else {
        continue;
      }
      if (cnt < 0) {
        return false;
      }
    }
    return (cnt == 0);
  }

  vector<string> removeInvalidParentheses(string s) {
    queue<string> q;
    unordered_set<string> visit;
    vector<string> ret;
    q.push(s);
    visit.insert(s);
    bool found = false;
    while (!q.empty()) {
      s = q.front();
      q.pop();

      if (IsValidString(s)) {
        ret.push_back(s);
        found = true;
      }
      if (found) {
        continue;
      }
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != '(' && s[i] != ')') {
          continue;
        }
        auto temp = s.substr(0, i) + s.substr(i + 1);
        if (visit.find(temp) == visit.end()) {
          q.push(temp);
          visit.insert(temp);
        }
      }
    }
    return ret;
  }
};