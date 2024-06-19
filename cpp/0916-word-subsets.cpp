#include <algorithm>
#include <array>
#include <cstddef>
#include <string>
#include <vector>

using namespace std;

using CharCounts = array<char, 26>;

CharCounts Count(const string &s) {
  CharCounts ans{};
  for (char c : s) {
    ans[c - 'a'] += 1;
  }
  return ans;
}

CharCounts Merge(const CharCounts &a, const CharCounts &b) {
  CharCounts ans{};
  for (size_t i = 0; i < a.size(); ++i) {
    ans[i] = max(a[i], b[i]);
  }
  return ans;
}

bool GE(const CharCounts &a, const CharCounts &b) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] > b[i]) {
      return false;
    }
  }
  return true;
}

class Solution {
public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    CharCounts universal;
    vector<string> ans;
    for (const auto &s : words2) {
      universal = Merge(universal, Count(s));
    }
    for (const auto &s : words1) {
      if (GE(universal, Count(s))) {
        ans.push_back(s);
      }
    }
    return ans;
  }
};

int main() { return 0; }
