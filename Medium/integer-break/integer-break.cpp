class Solution {
public:
  int integerBreak(int n) {
    uint64_t ret = 1;
    if (n == 2)
      return 1;
    if (n == 3)
      return 2;
    if (n == 4)
      return 4;
    while (n >= 5) {
      n -= 3;
      ret *= 3;
    }
    ret *= n;
    return ret;
  }
};