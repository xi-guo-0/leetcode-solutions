#include <bitset>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int countPrimeSetBits(int L, int R) {
    unordered_set<int> primeSet = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int count = 0;
    for (int i = L; i <= R; ++i) {
      int bitCount = bitset<32>(i).count();
      if (primeSet.find(bitCount) != primeSet.end()) {
        ++count;
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  int L = 10, R = 15;
  cout << sol.countPrimeSetBits(L, R) << endl;
  return 0;
}
