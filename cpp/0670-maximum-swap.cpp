#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int maximumSwap(int num) {
    string numStr = to_string(num);

    vector<int> lastIdx(10, -1);
    for (int i = 0; i < numStr.size(); ++i) {
      lastIdx[numStr[i] - '0'] = i;
    }

    for (int i = 0; i < numStr.size(); ++i) {
      for (int d = 9; d > numStr[i] - '0'; --d) {
        if (lastIdx[d] > i) {
          swap(numStr[i], numStr[lastIdx[d]]);
          return stoi(numStr);
        }
      }
    }
    return num;
  }
};
