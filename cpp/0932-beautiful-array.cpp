#include <vector>

using namespace std;

class Solution {
public:
  vector<int> beautifulArray(const int n) {
    vector<int> ans{1};
    while (ans.size() < n) {
      for (auto &i : ans) {
        i = i * 2 - 1;
      }
      int len = ans.size();
      for (int i = 0; i < len; ++i) {
        ans.push_back(ans[i] + 1);
      }
    }
    ans.erase(remove_if(ans.begin(), ans.end(), [n](int x) { return n < x; }),
              ans.end());
    return ans;
  }
};

int main() { return 0; }
