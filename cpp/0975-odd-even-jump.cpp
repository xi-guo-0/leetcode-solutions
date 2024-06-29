#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int oddEvenJumps(vector<int> &arr) {
    int n = arr.size();
    if (n == 1)
      return 1;

    vector<bool> oddJumpGood(n, false);
    vector<bool> evenJumpGood(n, false);
    oddJumpGood[n - 1] = evenJumpGood[n - 1] = true;

    map<int, int> indexMap;
    indexMap[arr[n - 1]] = n - 1;

    for (int i = n - 2; i >= 0; --i) {
      auto oddJump = indexMap.lower_bound(arr[i]);
      auto evenJump = indexMap.upper_bound(arr[i]);

      if (oddJump != indexMap.end()) {
        oddJumpGood[i] = evenJumpGood[oddJump->second];
      }
      if (evenJump != indexMap.begin()) {
        evenJumpGood[i] = oddJumpGood[prev(evenJump)->second];
      }
      indexMap[arr[i]] = i;
    }

    return count(oddJumpGood.begin(), oddJumpGood.end(), true);
  }
};

int main() { return 0; }
