class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int ret = 0;
    int prev = -prices[0];
    for (auto x : prices) {
      ret = max(ret, prev + x - fee);
      prev = max(prev, ret - x);
    }
    return ret;
  }
};