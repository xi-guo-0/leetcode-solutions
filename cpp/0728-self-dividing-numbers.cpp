#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> selfDividingNumbers(const int left, const int right) {
    vector<int> ans;
    for (int i = max(1, left); i <= right; i++)
      if (is_self_divide(i))
        ans.push_back(i);
    return ans;
  }

private:
  bool is_self_divide(const int n) {
    int i(n);
    while (i) {
      const int low(i % 10);
      if (low == 0 || n % low)
        return false;
      i /= 10;
    }
    return true;
  }
};

int main() { return 0; }
