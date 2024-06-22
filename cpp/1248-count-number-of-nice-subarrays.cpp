#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    int s = 0;
    map<int, int> sum;
    sum[s]++;
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 1) {
        s++;
      }
      if (s - k >= 0) {
        ret += sum[s - k];
      }
      sum[s]++;
    }
    return ret;
  }
};

int main() { return 0; }
