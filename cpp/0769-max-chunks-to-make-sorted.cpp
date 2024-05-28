#include <vector>

using namespace std;

class Solution {
public:
  int maxChunksToSorted(const vector<int> &arr) {
    if (arr.empty())
      return 0;
    int rbound = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
      rbound = max(rbound, arr[i]);
      if (i == rbound)
        ++ans;
    }
    return ans;
  }
};

int main() { return 0; }
