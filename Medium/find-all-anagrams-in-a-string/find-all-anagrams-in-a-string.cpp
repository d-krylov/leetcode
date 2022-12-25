class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> count;
    vector<int> ret;
    int offset = p.size();
    int right = 0;

    while (right < offset) {
      int x = count.count(s[right]) == 0 ? 0 : count[s[right]];
      count.insert_or_assign(s[right], x + 1);
      int y = count.count(p[right]) == 0 ? 0 : count[p[right]];
      count.insert_or_assign(p[right], y - 1);
      right++;
    }

    while (right <= s.size()) {
      bool empty = true;
      for (auto q : count) {
        if (q.second != 0) {
          empty = false;
          break;
        }
      }

      if (empty) {
        ret.emplace_back(right - offset);
      }

      int x = count.count(s[right]) == 0 ? 0 : count[s[right]];
      count.insert_or_assign(s[right], x + 1);
      count[s[right - offset]]--;
      right++;
    }

    return ret;
  }
};