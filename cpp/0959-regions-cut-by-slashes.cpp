#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int regionsBySlashes(vector<string> &grid) {
    if (grid.size() == 0) {
      return 0;
    }
    int n = grid.size();
    vector<int> v(n * n * 4, 0);
    generate(v.begin(), v.end(), [i = 0]() mutable { return i++; });
    auto find = [&v](int i) {
      while (i != v[i])
        i = v[i];
      return i;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        const int a = find(4 * (i * n + j));
        const int b = find(4 * (i * n + j) + 1);
        const int c = find(4 * (i * n + j) + 2);
        const int d = find(4 * (i * n + j) + 3);
        if (j + 1 < n) {
          const int right = find(4 * (i * n + j + 1) + 1);
          v[find(d)] = right;
        }
        if (i + 1 < n) {
          const int down = find(4 * ((i + 1) * n + j));
          v[find(c)] = down;
        }
        if (grid[i][j] == ' ') {
          v[find(a)] = v[find(b)] = v[find(c)] = find(d);
        } else if (grid[i][j] == '/') {
          v[find(a)] = find(b);
          v[find(c)] = find(d);
        } else {
          v[find(a)] = find(d);
          v[find(b)] = find(c);
        }
      }
    }
    set<int> s;
    for (int i : v)
      s.insert(find(i));
    return s.size();
  }
};

int main() { return 0; }
