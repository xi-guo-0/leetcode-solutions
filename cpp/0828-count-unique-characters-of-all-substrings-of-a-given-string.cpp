#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int uniqueLetterString(string s) {
    vector<vector<int>> index(26, vector<int>(2, -1));
    int res = 0, N = s.length(), mod = pow(10, 9) + 7;

    for (int i = 0; i < N; ++i) {
      int c = s[i] - 'A';
      res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
      index[c][0] = index[c][1];
      index[c][1] = i;
    }

    for (int c = 0; c < 26; ++c)
      res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;

    return res;
  }
};

int main() { return 0; }
