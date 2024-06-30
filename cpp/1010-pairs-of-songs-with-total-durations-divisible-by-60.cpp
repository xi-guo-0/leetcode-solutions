#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    vector<int> counts(60, 0);
    for (const auto &t : time)
      counts[t % 60]++;

    int64_t sum = (int64_t(counts[0]) * (counts[0] - 1)) / 2 +
                  (int64_t(counts[30]) * (counts[30] - 1)) / 2;

    for (int i = 1; i < 30; i++)
      sum += int64_t(counts[i]) * counts[60 - i];

    return static_cast<int>(sum);
  }
};

int main() { return 0; }
