#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numDupDigitsAtMostN(int n) {
    string s = to_string(n + 1);
    int len = s.size(), total = 0;

    for (int i = 1; i < len; ++i)
      total += 9 * A(9, i - 1);

    vector<bool> used(10, false);
    for (int i = 0; i < len; ++i) {
      for (int j = (i == 0 ? 1 : 0); j < s[i] - '0'; ++j) {
        if (!used[j]) {
          total += A(9 - i, len - i - 1);
        }
      }
      if (used[s[i] - '0'])
        break;
      used[s[i] - '0'] = true;
    }

    return n - total;
  }

private:
  int A(int n, int k) {
    int res = 1;
    for (int i = 0; i < k; ++i)
      res *= (n - i);
    return res;
  }
};

int main() { return 0; }
