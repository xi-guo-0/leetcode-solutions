#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool buddyStrings(const string &a, const string &b) {
    if (a.size() != b.size()) {
      return false;
    }
    vector<int> dif;
    for (int i = 0; i < a.size(); i++)
      if (a[i] != b[i]) {
        dif.push_back(i);
        if (dif.size() > 2) {
          return false;
        }
      }
    if (dif.size() == 0) {
      string t(a);
      sort(t.begin(), t.end());
      t.erase(unique(t.begin(), t.end()), t.end());
      return t.size() < a.size();
    } else if (dif.size() == 2) {
      return a[dif[0]] == b[dif[1]] && a[dif[1]] == b[dif[0]];
    }
    return false;
  }
};

int main() { return 0; }
