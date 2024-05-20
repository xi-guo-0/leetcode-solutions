#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int findMinMoves(vector<int> &machines) {
    int total = accumulate(machines.begin(), machines.end(), 0);
    int n = machines.size();
    if (total % n != 0)
      return -1;
    int target = total / n;
    int moves = 0;
    int accumulated = 0;

    for (int i = 0; i < n; ++i) {
      int diff = machines[i] - target;
      accumulated += diff;
      moves = max(moves, max(abs(accumulated), diff));
    }

    return moves;
  }
};
