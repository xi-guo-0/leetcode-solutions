#include <array>
#include <vector>

using namespace std;

class Solution {
public:
  int numFriendRequests(vector<int> &ages) {
    array<int, 121> count{};
    for (int age : ages) {
      ++count[age];
    }
    int ans = 0;
    for (int ageA = 0; ageA <= 120; ageA++) {
      int countA = count[ageA];
      for (int ageB = 0; ageB <= 120; ageB++) {
        int countB = count[ageB];
        if (ageA * 0.5 + 7 >= ageB)
          continue;
        if (ageA < ageB)
          continue;
        if (ageA < 100 && 100 < ageB)
          continue;
        ans += countA * countB;
        if (ageA == ageB)
          ans -= countA;
      }
    }
    return ans;
  }
};

int main() { return 0; }
