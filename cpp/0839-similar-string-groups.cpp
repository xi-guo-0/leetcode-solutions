#include <cstddef>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class UnionFind {
public:
  UnionFind(int n) : n(n), countOfConnectedComponents(n) {
    f.resize(n);
    for (int i = 0; i < n; ++i) {
      f[i] = i;
    }
  }

  int getCount() { return countOfConnectedComponents; }

  void unionOp(int x, int y) {
    int l = findOp(std::min(x, y));
    int r = findOp(std::max(x, y));
    if (l != r) {
      f[findOp(l)] = findOp(r);
      --countOfConnectedComponents;
    }
  }

  int findOp(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

private:
  int n;
  std::vector<int> f;
  int countOfConnectedComponents;
};

bool is_similar(const string &a, const string &b) {
  if (a.size() != b.size()) {
    return false;
  }
  vector<size_t> indices;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      indices.push_back(i);
      if (2 < indices.size()) {
        return false;
      }
    }
  }
  return indices.empty() ||
         (indices.size() == 2 && a[indices.front()] == b[indices.back()] &&
          a[indices.back()] == b[indices.front()]);
}

class Solution {
public:
  int numSimilarGroups(vector<string> &strs) {
    UnionFind uf(strs.size());
    for (size_t i = 0; i < strs.size(); ++i) {
      for (size_t j = i + 1; j < strs.size(); ++j) {
        const auto &a = strs[i];
        const auto &b = strs[j];
        if (is_similar(a, b)) {
          if (a <= b) {
            uf.unionOp(i, j);
          } else {
            uf.unionOp(j, i);
          }
        }
      }
    }
    return uf.getCount();
  }
};

int main() { return 0; }
