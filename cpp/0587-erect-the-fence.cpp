#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

bool comparetrees(const vector<int> &p1, const vector<int> &p2) {
  return (p1[0] < p2[0]) || (p1[0] == p2[0] && p1[1] < p2[1]);
}

int orientation(const vector<int> &p, const vector<int> &q,
                const vector<int> &r) {
  return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
}

class Solution {
public:
  vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
    int n = trees.size();
    if (n <= 1)
      return trees;

    ranges::sort(trees, comparetrees);

    vector<vector<int>> hull;

    for (int i = 0; i < n; ++i) {
      while (hull.size() >= 2 &&
             orientation(hull[hull.size() - 2], hull[hull.size() - 1],
                         trees[i]) < 0) {
        hull.pop_back();
      }
      hull.push_back(trees[i]);
    }

    for (int i = n - 2, t = hull.size() + 1; i >= 0; --i) {
      while (hull.size() >= t &&
             orientation(hull[hull.size() - 2], hull[hull.size() - 1],
                         trees[i]) < 0) {
        hull.pop_back();
      }
      hull.push_back(trees[i]);
    }

    hull.pop_back();

    ranges::sort(hull);
    auto it = unique(hull.begin(), hull.end());
    hull.resize(distance(hull.begin(), it));
    return hull;
  }
};
