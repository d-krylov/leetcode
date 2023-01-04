class Solution {
private:
  vector<string> ret;

public:
  void generate(uint64_t count, string s, uint64_t left, uint64_t right) {
    if (left == count && right == count) {
      ret.push_back(s);
    } else {
      if (left < count) {
        generate(count, s + '(', left + 1, right);
      }
      if (right < left) {
        generate(count, s + ')', left, right + 1);
      }
    }
  }

  vector<string> generateParenthesis(int n) {
    generate(n, "", 0, 0);
    return ret;
  }
};