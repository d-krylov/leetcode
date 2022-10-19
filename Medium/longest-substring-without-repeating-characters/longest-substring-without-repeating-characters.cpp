class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int left = 0;
    int right = 0;
    int m[256] = {0};
    int ret = 0;
    while (right < s.size()) {
      if (m[s[right]] != 0) {
        while (left < m[s[right]]) {
          m[s[left]] = 0;
          left++;
        }
      }
      m[s[right]] = right + 1;
      ret = max(right - left + 1, ret);
      right++;
    }
    return ret;
  }
};
