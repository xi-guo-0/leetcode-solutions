#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minDeletionSize(const vector<string> &strs) {
    if (strs.size() == 0 || strs[0].size() == 0) {
      return 0;
    }
    int ans = 0;
    for (int j = 0; j < strs[0].size(); j++)
      for (int i = 1; i < strs.size(); i++)
        if (strs[i][j] < strs[i - 1][j]) {
          ans++;
          break;
        }
    return ans;
  }
};

int main() { return 0; }
