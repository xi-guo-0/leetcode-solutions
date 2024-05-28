#include <algorithm>
#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    auto last_occur = LastOccur(s);
    vector<int> ans;
    for (int i = 0; i < s.size();) {
      char aim = s[i];
      int right = last_occur[aim];
      for (int j = i + 1; j < right; ++j) {
        right = max(right, last_occur[s[j]]);
      }
      ans.push_back(right - i + 1);
      i = right + 1;
    }
    return ans;
  }

private:
  array<int, 128> LastOccur(const string &s) {
    array<int, 128> ans{};
    for (int i = 0; i < s.size(); ++i) {
      ans[s[i]] = i;
    }
    return ans;
  }
};

int main() { return 0; }
