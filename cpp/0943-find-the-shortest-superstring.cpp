#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string shortestSuperstring(vector<string> &words) {
    int n = words.size();

    auto overlap = [](const string &a, const string &b) {
      int m = a.size(), n = b.size();
      for (int i = min(m, n); i >= 0; --i) {
        if (b.substr(0, i) == a.substr(m - i))
          return i;
      }
      return 0;
    };

    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));

    for (int mask = 0; mask < (1 << n); ++mask) {
      for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0)
          continue;
        int prev_mask = mask ^ (1 << i);

        if (prev_mask == 0) {
          dp[mask][i] = words[i].size();
        } else {
          for (int j = 0; j < n; ++j) {
            if ((prev_mask & (1 << j)) == 0)
              continue;
            int len = dp[prev_mask][j] + words[i].size() -
                      overlap(words[j], words[i]);
            if (len < dp[mask][i]) {
              dp[mask][i] = len;
              parent[mask][i] = j;
            }
          }
        }
      }
    }

    int min_len = INT_MAX, end_index = -1;
    for (int i = 0; i < n; ++i) {
      if (dp[(1 << n) - 1][i] < min_len) {
        min_len = dp[(1 << n) - 1][i];
        end_index = i;
      }
    }

    int mask = (1 << n) - 1;
    vector<int> path;
    while (end_index != -1) {
      path.push_back(end_index);
      int next_index = parent[mask][end_index];
      mask ^= (1 << end_index);
      end_index = next_index;
    }
    reverse(path.begin(), path.end());

    string superstring = words[path[0]];
    for (int i = 1; i < path.size(); ++i) {
      int overlap_len = overlap(superstring, words[path[i]]);
      superstring += words[path[i]].substr(overlap_len);
    }

    return superstring;
  }
};

int main() { return 0; }
