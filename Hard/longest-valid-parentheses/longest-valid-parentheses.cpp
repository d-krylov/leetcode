class Solution {
public:
  int longestValidParentheses(string s) {
    auto n = s.size();
    int ret = 0;
    stack<int> q;
    q.push(-1);
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        q.push(i);
      } else {
        if (!q.empty()) {
          q.pop();
        }
        if (!q.empty()) {
          ret = max(ret, i - q.top());
        } else {
          q.push(i);
        }
      }
    }
    return ret;
  }
};