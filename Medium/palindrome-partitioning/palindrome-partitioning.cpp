class Solution {
public:
  bool IsPalindrome(string s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }
    return true;
  }

  void GetPalindroms(vector<vector<string>> &ret, vector<string> &v, string &s,
                     int begin, int end) {
    if (begin >= end) {
      ret.push_back(v);
      return;
    }
    for (int i = begin; i < end; i++) {
      if (IsPalindrome(s, begin, i)) {
        v.push_back(s.substr(begin, i - begin + 1));
        GetPalindroms(ret, v, s, i + 1, end);
        v.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    auto n = s.size();
    vector<vector<string>> ret;
    vector<string> v;
    GetPalindroms(ret, v, s, 0, n);
    return ret;
  }
};