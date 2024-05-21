#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int arrayNesting(std::vector<int> &nums) {
    int n = nums.size();
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
      uf.unionOp(i, nums[i]);
    }
    std::unordered_map<int, int> cnt;
    int ans = 0;
    for (int x : nums) {
      int v = uf.findOp(x);
      cnt[v] = 1 + cnt[v];
      ans = std::max(ans, cnt[v]);
    }
    return ans;
  }

private:
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
};
