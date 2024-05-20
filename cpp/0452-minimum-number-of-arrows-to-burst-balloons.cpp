class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(
        points.begin(), points.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    int result = 0;
    for (int i = 0; i < points.size();) {
      vector<int> p(points[i]);
      int j = i + 1;
      for (; j < points.size() && p[0] <= points[j][1] && points[j][0] <= p[1];
           j++) {
        p[0] = max(p[0], points[j][0]);
        p[1] = min(p[1], points[j][1]);
      }
      result++;
      i = j;
    }
    return result;
  }
};
