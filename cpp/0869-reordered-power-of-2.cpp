#include <algorithm>
#include <array>
#include <set>
#include <string>

using namespace std;

constexpr array<int, 31> generatePowerOf2Array() {
  array<int, 31> arr = {};
  for (int i = 0; i < 31; ++i) {
    arr[i] = 1 << i;
  }
  return arr;
}

const set<int> powerOf2 = [] {
  set<int> powerOf2Set;
  constexpr auto powerOf2Array = generatePowerOf2Array();
  for (int val : powerOf2Array) {
    powerOf2Set.insert(val);
  }
  return powerOf2Set;
}();

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    string numStr = to_string(n);
    sort(numStr.begin(), numStr.end());
    return isPermutationPowerOf2(numStr);
  }

private:
  bool isPermutationPowerOf2(string &numStr) {
    do {
      if (numStr[0] != '0') {
        int permutedNum = stoi(numStr);
        if (powerOf2.find(permutedNum) != powerOf2.end()) {
          return true;
        }
      }
    } while (next_permutation(numStr.begin(), numStr.end()));
    return false;
  }
};

int main() { return 0; }
