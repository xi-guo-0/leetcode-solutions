#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> numberOfLines(const vector<int> &widths, const string &S) {
    const int maximum = 100;
    int used = 0;
    int lines = 1;

    for (size_t i = 0; i < S.length(); ++i) {
      used += widths[S[i] - 'a'];
      if (used > maximum) {
        used = 0;
        lines += 1;
        --i;
      }
    }

    return {lines, used};
  }
};

int main() { return 0; }
