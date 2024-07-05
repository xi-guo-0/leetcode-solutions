#include <bitset>

using namespace std;

constexpr int bound = 40000;
constexpr int capacity = 80000;

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    bitset<80000> F;
    F.reset();
    F[bound] = 1;

    for (int stone : stones) {
      F = (F << stone) | (F >> stone);
    }
    for (int i = 0; i < 30000; i++) {
      if (F[bound + i])
        return i;
    }
    return -1;
  }
};

int main() { return 0; }