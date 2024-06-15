#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numSpecialEquivGroups(const vector<string> &A) {
    set<string> ans;
    for (const auto &s : A) {
      string odds;
      string evens;
      for (int i = 0; i < s.size(); i++)
        i % 2 ? odds += s[i] : evens += s[i];
      sort(odds.begin(), odds.end());
      sort(evens.begin(), evens.end());
      ans.insert(odds + evens);
    }
    return ans.size();
  }
};

int main() { return 0; }
