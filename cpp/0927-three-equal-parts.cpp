#include <vector>

using namespace std;

class Solution {
public:
  vector<int> threeEqualParts(vector<int> &arr) {
    int n = arr.size();

    int countOnes = 0;
    for (int num : arr) {
      if (num == 1)
        countOnes++;
    }

    if (countOnes == 0)
      return {0, 2};
    if (countOnes % 3 != 0)
      return {-1, -1};

    int eachPartOnes = countOnes / 3;

    int start1 = -1, start2 = -1, start3 = -1;
    int onesCount = 0;

    for (int i = 0; i < n; ++i) {
      if (arr[i] == 1) {
        onesCount++;
        if (onesCount == 1)
          start1 = i;
        else if (onesCount == eachPartOnes + 1)
          start2 = i;
        else if (onesCount == 2 * eachPartOnes + 1)
          start3 = i;
      }
    }

    while (start3 < n && arr[start1] == arr[start2] &&
           arr[start2] == arr[start3]) {
      start1++;
      start2++;
      start3++;
    }

    if (start3 == n)
      return {start1 - 1, start2};

    return {-1, -1};
  }
};

int main() { return 0; }
