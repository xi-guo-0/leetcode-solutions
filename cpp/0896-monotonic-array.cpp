#include <vector>

using namespace std;

class Solution {
public:
  bool isMonotonic(const vector<int> &A) {
    bool increasing = true;
    bool decreasing = true;
    for (int i = 1; i < A.size(); i++)
      if (A[i - 1] > A[i])
        increasing = false;
      else if (A[i - 1] < A[i])
        decreasing = false;
    return increasing || decreasing;
  }
};

int main() { return 0; }
