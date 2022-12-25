class Solution {
public:
  int reverse(int x) {
    int64_t temp = 0;
    while (x != 0) {
      temp = temp * 10 + x % 10;
      x /= 10;
    }
    return (temp < INT_MIN || temp > INT_MAX) ? 0 : temp;
  }
};