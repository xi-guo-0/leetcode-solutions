#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numSquarefulPerms(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> freq;
    for (int num : nums) {
      ++freq[num];
    }
    return dfs(nums, freq, -1, 0, nums.size());
  }

private:
  int dfs(const vector<int> &nums, unordered_map<int, int> &freq, int prev,
          int length, int target) {
    if (length == target) {
      return 1;
    }
    int count = 0;
    for (auto &entry : freq) {
      if (entry.second > 0 && (prev == -1 || isSquareful(prev, entry.first))) {
        --entry.second;
        count += dfs(nums, freq, entry.first, length + 1, target);
        ++entry.second;
      }
    }
    return count;
  }

  bool isSquareful(int a, int b) {
    int sum = a + b;
    int sqrt_sum = sqrt(sum);
    return sqrt_sum * sqrt_sum == sum;
  }
};

int main() { return 0; }
