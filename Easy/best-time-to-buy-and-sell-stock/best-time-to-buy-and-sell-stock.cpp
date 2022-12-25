class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int m = prices[0];
    int ret = 0;
    for (auto &x : prices) {
      m = min(x, m);
      ret = max(ret, x - m);
    }
    return ret;
  }
};