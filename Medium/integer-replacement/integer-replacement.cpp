class Solution {
public:
  int integerReplacement(int n) {
    int cnt = 0;
    if (n == INT_MAX) {
      return 32;
    }
    while (n != 1) {
      if (n % 2 == 0) {
        n >>= 1;
      } else {
        if (n == 3) {
          cnt += 2;
          break;
        }
        n += (n % 4) - 2;
      }
      cnt++;
    }
    return cnt;
  }
};