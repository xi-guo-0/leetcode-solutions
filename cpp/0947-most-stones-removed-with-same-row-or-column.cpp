#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
  unordered_map<int, int> parent;

  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  void union_op(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      parent[rootY] = rootX;
    }
  }

public:
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();
    if (n < 2)
      return 0;

    for (auto &stone : stones) {
      int x = -stone[0];
      int y = stone[1];
      parent[x] = x;
      parent[y + 10000] = y + 10000;
    }

    for (auto &stone : stones) {
      int x = -stone[0];
      int y = stone[1];
      union_op(x, y + 10000);
    }

    unordered_set<int> roots;
    for (auto &stone : stones) {
      int x = -stone[0];
      roots.insert(find(x));
    }

    return n - roots.size();
  }
};

int main() { return 0; }
