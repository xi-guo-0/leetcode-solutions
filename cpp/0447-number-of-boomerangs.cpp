class Solution {
public:
  int numberOfBoomerangs(const vector<vector<int>> &points) {
    int result = 0;
    for (const auto &p : points) {
      map<int, int> dict;
      for (const auto &q : points) {
        if (p != q) {
          const int d =
              (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
          if (dict.count(d)) {
            result += dict[d] * 2;
            dict[d]++;
          } else {
            dict[d] = 1;
          }
        }
      }
    }
    return result;
  }
};
