#include <cstddef>
#include <vector>

using namespace std;

bool is_odd(int x) { return x % 2 != 0; }

class Solution {
public:
  bool threeConsecutiveOdds(vector<int> &arr) {
    bool ans = false;
    for (size_t i = 2; i < arr.size(); ++i) {
      if (is_odd(arr[i]) && is_odd(arr[i - 1]) && is_odd(arr[i - 2])) {
        ans = true;
        break;
      }
    }
    return ans;
  }
};

int main() { return 0; }
