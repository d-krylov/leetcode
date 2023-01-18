class Solution {
public:
  int longestIdealString(string s, int k) {
    auto n = s.size();
    int d[26] = {0};
    int ret = 0;
    for (char ch : s) {
      int pos = ch - 'a';
      d[pos]++;
      int left = (pos < k) ? 0 : (pos - k);
      int right = (pos > 25 - k) ? 25 : (pos + k);
      for (int j = left; j <= right; j++) {
        if (j != pos) {
          d[pos] = max(d[pos], d[j] + 1);
        }
      }
      ret = max(ret, d[pos]);
    }
    return ret;
  }
};