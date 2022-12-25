class Solution {
public:
  vector<int> partitionLabels(string s) {
    int m[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      m[s[i] - 'a'] = i;
    }
    vector<int> ret;
    int end = 0;
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
      last = max(last, m[s[i] - 'a']);
      if (i == last) {
        ret.push_back(i - end + 1);
        end = i + 1;
      }
    }
    return ret;
  }
};
