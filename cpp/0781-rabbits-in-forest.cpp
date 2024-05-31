#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numRabbits(const vector<int> &answers) {
    unordered_map<int, int> counts;
    for (int answer : answers) {
      counts[answer]++;
    }

    int totalRabbits = 0;
    for (const auto &[answer, count] : counts) {
      int groupSize = answer + 1;
      int groups = ceil(static_cast<double>(count) / groupSize);
      totalRabbits += groups * groupSize;
    }

    return totalRabbits;
  }
};

int main() { return 0; }
