class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    auto n = pushed.size();
    int ipush = 0;
    int ipop = 0;
    while (ipush < n && ipop < n) {
      s.push(pushed[ipush++]);
      while (!s.empty()) {
        if (s.top() != popped[ipop]) {
          break;
        }
        s.pop();
        ipop++;
      }
    }
    return s.empty();
  }
};