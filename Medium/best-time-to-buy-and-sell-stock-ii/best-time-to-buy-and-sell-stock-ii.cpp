class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ret = 0;
    int prev = prices[0];
    for (auto x : prices) {
      if (x > prev) {
        ret += x - prev;
      }
      prev = x;
    }
    return ret;
  }
};