class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    auto n = gas.size();
    int sum = 0;
    int ret = 0;
    int x = 0;
    for (int i = 0; i < n; i++) {
      x += gas[i] - cost[i];
      sum += gas[i] - cost[i];
      if (x < 0) {
        x = 0;
        ret = i + 1;
      }
    }
    return sum >= 0 ? ret : -1;
  }
};