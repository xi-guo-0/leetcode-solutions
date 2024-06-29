#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    if (arr.size() < 2)
      return arr.size();

    int maxLength = 1;
    int inc = 1, dec = 1;

    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] > arr[i - 1]) {
        inc = dec + 1;
        dec = 1;
      } else if (arr[i] < arr[i - 1]) {
        dec = inc + 1;
        inc = 1;
      } else {
        inc = dec = 1;
      }
      maxLength = max(maxLength, max(inc, dec));
    }

    return maxLength;
  }
};

int main() { return 0; }
