class Solution {
public:
  int maxPoints(const vector<vector<int>> &points) {
    if (points.size() < 3)
      return points.size();
    int ans = 0;
    unordered_map<long double, int> slope_count;
    for (int i = 0; i < points.size() - 1; i++) {
      slope_count.clear();
      int same_point_num = 0; // Number of points that coincide with i
      int point_max = 1;      // Number of points collinear with i
      for (int j = i + 1; j < points.size(); j++) {
        long double slope;
        if (points[i][0] == points[j][0]) {
          slope = std::numeric_limits<long double>::infinity();
          if (points[i][1] == points[j][1]) {
            ++same_point_num;
            continue;
          }
        } else {
          slope = static_cast<long double>(points[i][1] - points[j][1]) /
                  (points[i][0] - points[j][0]);
        }
        int count = 0;
        if (slope_count.count(slope))
          count = ++slope_count[slope];
        else {
          count = 2;
          slope_count[slope] = 2;
        }
        if (point_max < count)
          point_max = count;
      }
      ans = max(ans, point_max + same_point_num);
    }
    return ans;
  }
};
