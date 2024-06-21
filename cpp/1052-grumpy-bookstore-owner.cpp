#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    int n = customers.size();
    int satisfied = 0;

    for (int i = 0; i < n; ++i) {
      if (grumpy[i] == 0) {
        satisfied += customers[i];
      }
    }

    int maxAdditional = 0;
    int currentAdditional = 0;

    for (int i = 0; i < n; ++i) {
      if (grumpy[i] == 1) {
        currentAdditional += customers[i];
      }

      if (i >= minutes) {
        if (grumpy[i - minutes] == 1) {
          currentAdditional -= customers[i - minutes];
        }
      }

      maxAdditional = max(maxAdditional, currentAdditional);
    }

    return satisfied + maxAdditional;
  }
};

int main() { return 0; }
