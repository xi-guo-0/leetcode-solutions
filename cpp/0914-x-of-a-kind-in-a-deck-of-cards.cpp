#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  bool hasGroupsSizeX(const vector<int> &deck) {
    if (deck.empty())
      return false;

    vector<int> cnt(10000, 0);
    for (int n : deck)
      cnt[n]++;

    int common = accumulate(cnt.begin(), cnt.end(), 0, [](int a, int b) {
      return b == 0 ? a : gcd(b, a % b);
    });

    return common > 1;
  }
};

int main() { return 0; }
