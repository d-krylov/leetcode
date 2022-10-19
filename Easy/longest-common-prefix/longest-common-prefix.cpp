class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string ret;
    for (int i = 0; i < strs[0].size(); i++) {
      char p = strs[0][i];
      for (int j = 0; j < strs.size(); j++) {
        if (strs[j].size() >= i) {
          if (strs[j][i] == p) {
            continue;
          }
          return ret;
        }
      }
      ret += p;
    }
    return ret;
  }
};
