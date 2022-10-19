class Solution {
public:
  bool isValid(string s) {
    std::stack<char> q;
    for (char ch : s) {
      if (ch == '(' || ch == '[' || ch == '{')
        q.push(ch);
      else {
        if (q.empty())
          return false;
        switch (ch) {
        case ')':
          if (q.top() != '(')
            return false;
          q.pop();
          break;
        case ']':
          if (q.top() != '[')
            return false;
          q.pop();
          break;
        case '}':
          if (q.top() != '{')
            return false;
          q.pop();
          break;
        }
      }
    }
    if (q.empty())
      return true;
    return false;
  }
};
