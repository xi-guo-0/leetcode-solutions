#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    vector<vector<int>> ans;
    vector<vector<int>> h(buildings.size() * 2, vector<int>(2));
    for (int i = 0; i < buildings.size(); ++i) {
      h[2 * i][0] = buildings[i][0];
      h[2 * i][1] = -buildings[i][2];
      h[2 * i + 1][0] = buildings[i][1];
      h[2 * i + 1][1] = buildings[i][2];
    }
    sort(h.begin(), h.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
    });

    map<int, int> m;
    m[0] = 1;
    int last = 0;

    for (const vector<int> &p : h) {
      if (p[1] < 0) {
        m[(-1) * p[1]]++;
      } else {
        m[p[1]]--;
        if (m[p[1]] == 0) {
          m.erase(p[1]);
        }
      }
      int maxHeight = m.rbegin()->first;
      if (last != maxHeight) {
        last = maxHeight;
        ans.push_back({p[0], last});
      }
    }
    return ans;
  }
};
