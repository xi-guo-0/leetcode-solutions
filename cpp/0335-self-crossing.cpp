#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isSelfCrossing(vector<int> &distance) {
    const auto &s = distance;
    int n = s.size();
    if (n <= 3)
      return false;

    for (int i = 3; i < n; i++) {
      if (s[i] >= s[i - 2] && s[i - 1] <= s[i - 3])
        return true;
      if (i >= 4 && s[i - 1] == s[i - 3] && s[i] + s[i - 4] >= s[i - 2])
        return true;
      if (i >= 5 && s[i - 2] - s[i - 4] >= 0 && s[i] >= s[i - 2] - s[i - 4] &&
          s[i - 1] >= s[i - 3] - s[i - 5] && s[i - 1] <= s[i - 3])
        return true;
    }
    return false;
  }
};

int main() {}
