class Solution {
public:
  int characterReplacement(string s, int k) {
    int m[26] = {0};
    int left = 0;
    int ret = 0;
    for (int right = 0; right < s.size(); right++) {
      m[s[right] - 'A']++;
      int maximum = 0;
      for (auto x : m) {
        maximum = max(maximum, x);
      }
      while (right - left + 1 - maximum > k) {
        m[s[left++] - 'A']--;
      }
      ret = max(ret, right - left + 1);
    }
    return ret;
  }
};