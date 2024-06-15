#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
    unordered_set<int> sb(bobSizes.begin(), bobSizes.end());
    long long dif = 0;
    for (const auto &n : bobSizes)
      dif += n;
    for (const auto &n : aliceSizes)
      dif -= n;
    dif /= 2;
    for (const auto &n : aliceSizes)
      if (sb.find(n + dif) != sb.end())
        return vector<int>{n, static_cast<int>(n + dif)};
    return vector<int>{0, 0};
  }
};

int main() { return 0; }
