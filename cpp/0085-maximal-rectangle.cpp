class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }
    const int R = matrix.size(), C = matrix[0].size();
    int ans = 0;
    vector<int> heights(C + 1, 0);
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        heights[c] = (matrix[r][c] - '0' == 1) ? heights[c] + 1 : 0;
      }
      ans = max(ans, largestRectangleArea(heights));
    }
    return ans;
  }

private:
  int largestRectangleArea(vector<int> const &heights) {
    stack<int> stk;
    int ans = 0;

    for (int i = 0; i < heights.size();) {
      if (stk.empty() || heights[stk.top()] < heights[i]) {
        stk.push(i);
        ++i;
      } else {
        int temp = stk.top();
        stk.pop();
        ans = max(ans, heights[temp] * (stk.empty() ? i : i - stk.top() - 1));
      }
    }
    return ans;
  }
};
