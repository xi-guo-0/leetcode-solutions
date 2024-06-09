#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    std::unordered_map<int, int> remainderFreq;
    remainderFreq[0] = 1;
    int sum = 0, count = 0;

    for (int num : nums) {
      sum += num;
      int remainder = (sum % k + k) % k;
      if (remainderFreq.find(remainder) != remainderFreq.end()) {
        count += remainderFreq[remainder];
      }
      remainderFreq[remainder]++;
    }

    return count;
  }
};

int main() { return 0; }
