#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int scoreOfString(string s) {
    int ans = 0;
    for (size_t i = 1; i < s.size(); ++i) {
      ans += abs(s[i - 1] - s[i]);
    }
    return ans;
  }
};

int main() { return 0; }
