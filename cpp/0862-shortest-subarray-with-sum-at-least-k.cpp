#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int64_t> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i)
      prefix_sum[i + 1] = prefix_sum[i] + nums[i];

    int minLen = n + 1;
    deque<int> indices;
    for (int i = 0; i < n + 1; ++i) {
      while (!indices.empty() &&
             prefix_sum[i] - prefix_sum[indices.front()] >= k) {
        minLen = min(minLen, i - indices.front());
        indices.pop_front();
      }
      while (!indices.empty() && prefix_sum[i] <= prefix_sum[indices.back()])
        indices.pop_back();
      indices.push_back(i);
    }

    return minLen == n + 1 ? -1 : minLen;
  }
};

int main() { return 0; }
