#include <string>

using namespace std;

class Solution {
public:
  int numJewelsInStones(string J, string S) {
    int result = 0;
    int counts[128] = {0};
    for (auto i : S) {
      counts[i]++;
    }
    for (auto i : J) {
      result += counts[i];
    }
    return result;
  }
};

int main() { return 0; }
