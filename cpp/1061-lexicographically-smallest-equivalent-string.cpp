#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class UnionFind {
public:
  UnionFind(int n) : n(n), countOfConnectedComponents(n), f(n) {
    iota(f.begin(), f.end(), 0);
  }

  int GetCount() { return countOfConnectedComponents; }

  bool IsConnected(int x, int y) { return find(x) == find(y); }

  void Union(int x, int y) {
    int l = find(x);
    int r = find(y);
    if (l != r) {
      f[max(l, r)] = min(l, r);
      countOfConnectedComponents -= 1;
    }
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

private:
  int n;
  int countOfConnectedComponents;
  vector<int> f;
};

int code(char c) { return c - 'a'; }

char decode(int i) { return i + 'a'; }

class Solution {
public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    UnionFind uf(26);
    for (int i = 0; i < s1.size(); ++i) {
      uf.Union(code(s1[i]), code(s2[i]));
    }
    ostringstream oss;
    for (int i = 0; i < baseStr.length(); ++i) {
      oss << decode(uf.find(code(baseStr[i])));
    }
    return oss.str();
  }
};

int main() { return 0; }