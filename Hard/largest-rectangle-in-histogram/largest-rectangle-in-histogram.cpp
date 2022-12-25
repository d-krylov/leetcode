class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    auto n = heights.size();
    stack<int> s;
    int top;
    int ret_area = 0;
    int current_area;
    int i = 0;
    while (i < n) {
      if (s.empty() || heights[s.top()] <= heights[i]) {
        s.push(i++);
      } else {
        top = s.top();
        s.pop();
        current_area = heights[top] * (s.empty() ? i : i - s.top() - 1);
        ret_area = max(ret_area, current_area);
      }
    }
    while (!s.empty()) {
      top = s.top();
      s.pop();
      current_area = heights[top] * (s.empty() ? n : n - s.top() - 1);
      ret_area = max(ret_area, current_area);
    }
    return ret_area;
  }
};