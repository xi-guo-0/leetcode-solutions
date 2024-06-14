#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int lenLongestFibSubseq(vector<int> &arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int maxLength = 0;
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int a = arr[i];
        int b = arr[j];
        int length = 2;
        while (s.find(a + b) != s.end()) {
          b = a + b;
          a = b - a;
          length++;
        }
        maxLength = max(maxLength, length);
      }
    }

    return maxLength > 2 ? maxLength : 0;
  }
};

int main() { return 0; }
