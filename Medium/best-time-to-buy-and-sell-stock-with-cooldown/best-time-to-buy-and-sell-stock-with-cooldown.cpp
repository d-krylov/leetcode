class Solution {
public:
  int maxProfit(vector<int> &prices) {

    int ret = 0;
    int previous1 = -prices[0];
    int previous2 = 0;

    for (int x : prices) {
      int previous_ret = ret;
      ret = max(ret, previous1 + x);
      previous1 = max(previous1, previous2 - x);
      previous2 = previous_ret;
    }

    return ret;
  }
};