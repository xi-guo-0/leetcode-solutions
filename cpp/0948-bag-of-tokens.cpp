#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int bagOfTokensScore(vector<int> &tokens, int power) {
    int ans = 0;
    int points = 0;
    sort(tokens.begin(), tokens.end());
    for (int lo = 0, hi = tokens.size() - 1;
         lo <= hi && (tokens[lo] <= power || 0 < points);) {
      while (lo <= hi && tokens[lo] <= power) {
        power -= tokens[lo];
        ++lo;
        ++points;
      }
      ans = max(ans, points);
      if (lo <= hi && 0 < points) {
        power += tokens[hi];
        --hi;
        --points;
      }
    }
    return ans;
  }
};

int main() { return 0; }
