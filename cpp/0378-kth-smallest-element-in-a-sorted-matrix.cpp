#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    priority_queue<int, vector<int>, less<int>> maxPQ;
    for (const auto &row : matrix) {
      for (int num : row) {
        if (maxPQ.size() == k && num > maxPQ.top())
          break;
        maxPQ.push(num);
        if (maxPQ.size() > k)
          maxPQ.pop();
      }
    }
    return maxPQ.top();
  }
};
