#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> result;
    int n = target.size();
    bool changed = true;

    while (changed) {
      changed = false;
      for (int i = 0; i <= n - stamp.size(); ++i) {
        int j = 0;
        bool matched = false;
        for (j = 0; j < stamp.size(); ++j) {
          if (target[i + j] == '*')
            continue;
          if (target[i + j] != stamp[j])
            break;
          matched = true;
        }
        if (j == stamp.size() && matched) {
          fill(target.begin() + i, target.begin() + i + stamp.size(), '*');
          result.push_back(i);
          changed = true;
        }
      }
    }

    if (target != string(n, '*')) {
      return {};
    }

    reverse(result.begin(), result.end());
    return result;
  }
};

int main() { return 0; }
