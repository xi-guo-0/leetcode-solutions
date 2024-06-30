#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int> &nums) {
    int n = 0;
    vector<bool> result;
    for (const auto &i : nums) {
      n = (n * 2 + i) % 5;
      result.push_back(n == 0);
    }
    return result;
  }
};

int main() { return 0; }
