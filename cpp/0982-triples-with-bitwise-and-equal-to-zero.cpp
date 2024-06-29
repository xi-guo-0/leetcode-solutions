#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int countTriplets(vector<int> &nums) {
    unordered_map<int, int> countMap;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        countMap[nums[i] & nums[j]]++;
      }
    }

    int result = 0;

    for (int k = 0; k < n; ++k) {
      for (const auto &[key, count] : countMap) {
        if ((nums[k] & key) == 0) {
          result += count;
        }
      }
    }

    return result;
  }
};

int main() { return 0; }
