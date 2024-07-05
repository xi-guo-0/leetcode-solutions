#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> q(stones.begin(), stones.end());
    while (1 < q.size()) {
      const int a = q.top();
      q.pop();
      const int b = q.top();
      q.pop();
      if (a != b)
        q.push(a - b);
    }
    return q.empty() ? 0 : q.top();
  }
};

int main() { return 0; }