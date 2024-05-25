#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

struct SegmentTree {
  SegmentTree(int size) : size(size), tree(2 * size), lazy(2 * size) {}

  void update(int left, int right, int height) {
    left += size;
    right += size;

    tree[left] = max(tree[left], height);
    tree[right] = max(tree[right], height);

    if (left != right) {
      if (!(left & 1))
        lazy[left + 1] = max(lazy[left + 1], height);
      if (right & 1)
        lazy[right - 1] = max(lazy[right - 1], height);
    }

    left >>= 1;
    right >>= 1;

    while (left != right) {
      tree[left] = max(tree[2 * left], tree[2 * left + 1]);
      tree[right] = max(tree[2 * right], tree[2 * right + 1]);

      if (left / 2 != right / 2) {
        if (!(left & 1))
          lazy[left + 1] = max(lazy[left + 1], height);
        if (right & 1)
          lazy[right - 1] = max(lazy[right - 1], height);
      }

      left >>= 1;
      right >>= 1;
    }

    while (left > 0) {
      tree[left] = max(tree[2 * left], tree[2 * left + 1]);
      left >>= 1;
    }
  }

  int query(int left, int right) {
    left += size;
    right += size;

    int max_height = max(tree[left], tree[right]);

    while (left / 2 != right / 2) {
      if (!(left & 1)) {
        max_height = max(tree[left + 1], max_height);
        max_height = max(lazy[left + 1], max_height);
      }
      if (right & 1) {
        max_height = max(tree[right - 1], max_height);
        max_height = max(lazy[right - 1], max_height);
      }

      max_height = max(max_height, lazy[left]);
      max_height = max(max_height, lazy[right]);

      left >>= 1;
      right >>= 1;
    }

    max_height = max(max_height, lazy[right]);

    while (left / 2 > 0) {
      max_height = max(lazy[left], max_height);
      left >>= 1;
    }

    return max_height;
  }

  int size;
  vector<int> tree;
  vector<int> lazy;
};

class Solution {
public:
  vector<int> fallingSquares(vector<vector<int>> &positions) {
    vector<int> points;
    for (const auto &rect : positions) {
      points.push_back(rect[0]);
      points.push_back(rect[0] + rect[1] - 1);
    }

    sort(points.begin(), points.end());
    auto new_end = unique(points.begin(), points.end());
    points.resize(distance(points.begin(), new_end));

    SegmentTree st(points.size());

    vector<int> results;
    int max_height = 0;

    for (const auto &rect : positions) {
      int left = distance(points.begin(),
                          lower_bound(points.begin(), points.end(), rect[0]));
      int right =
          distance(points.begin(), lower_bound(points.begin(), points.end(),
                                               rect[0] + rect[1] - 1));

      int current_height = st.query(left, right);
      int new_height = rect[1] + current_height;
      max_height = max(new_height, max_height);
      st.update(left, right, new_height);
      results.push_back(max_height);
    }

    return results;
  }
};
