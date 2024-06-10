#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 205;

class SegmentTree {
private:
  struct Node {
    int start, end, count;
    long long length;
  };

  vector<Node> segTree;
  vector<int> ys;

  void pushUp(int index) {
    if (segTree[index].count > 0) {
      segTree[index].length =
          ys[segTree[index].end + 1] - ys[segTree[index].start];
    } else if (segTree[index].start != segTree[index].end) {
      segTree[index].length =
          segTree[2 * index].length + segTree[2 * index + 1].length;
    } else {
      segTree[index].length = 0;
    }
  }

  void update(int index, int l, int r, int delta) {
    if (segTree[index].start == l && segTree[index].end == r) {
      segTree[index].count += delta;
      pushUp(index);
      return;
    }
    int mid = (segTree[index].start + segTree[index].end) / 2;
    if (r <= mid) {
      update(2 * index, l, r, delta);
    } else if (l > mid) {
      update(2 * index + 1, l, r, delta);
    } else {
      update(2 * index, l, mid, delta);
      update(2 * index + 1, mid + 1, r, delta);
    }
    pushUp(index);
  }

public:
  SegmentTree(int n) : segTree(4 * n) {}

  void build(int index, int l, int r) {
    segTree[index].start = l;
    segTree[index].end = r;
    segTree[index].count = 0;
    segTree[index].length = 0;
    if (l != r) {
      int mid = (l + r) / 2;
      build(2 * index, l, mid);
      build(2 * index + 1, mid + 1, r);
    }
  }

  void update(int l, int r, int delta) { update(1, l, r, delta); }

  long long query() const { return segTree[1].length; }

  void setYs(const vector<int> &yCoords) { ys = yCoords; }
};

class Solution {
public:
  int rectangleArea(vector<vector<int>> &rectangles) {
    vector<int> ys;
    vector<array<int, 4>> events;

    for (const auto &rect : rectangles) {
      ys.push_back(rect[1]);
      ys.push_back(rect[3]);
      events.push_back({rect[0], rect[1], rect[3], 1});
      events.push_back({rect[2], rect[1], rect[3], -1});
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    sort(events.begin(), events.end());

    SegmentTree tree(ys.size());
    tree.setYs(ys);
    tree.build(1, 0, ys.size() - 2);

    long long area = 0;
    int prev_x = events[0][0];

    for (const auto &event : events) {
      int current_x = event[0];
      long long width = current_x - prev_x;
      if (width > 0) {
        long long height = tree.query();
        area += width * height;
      }

      int y1_idx = lower_bound(ys.begin(), ys.end(), event[1]) - ys.begin();
      int y2_idx = lower_bound(ys.begin(), ys.end(), event[2]) - ys.begin() - 1;
      tree.update(y1_idx, y2_idx, event[3]);

      prev_x = current_x;
    }

    return area % static_cast<int>(1'000'000'007);
  }
};

int main() { return 0; }
