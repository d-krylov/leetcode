class Solution {
public:
  int countPrimes(int n) {
    vector<int> prime(n + 1, 0);
    int ret = 0;
    for (int64_t i = 2; i < n; i++) {
      if (prime[i] == 0) {
        ret++;
        if (i * i < n) {
          for (int j = i * i; j < n; j += i) {
            prime[j] = 1;
          }
        }
      }
    }
    return ret;
  }
};