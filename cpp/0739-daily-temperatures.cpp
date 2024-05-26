#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(const vector<int> &T) {
    int n = T.size();
    vector<int> result(n, 0);
    stack<int> s;

    for (int i = 0; i < n; ++i) {

      while (!s.empty() && T[i] > T[s.top()]) {
        int idx = s.top();
        s.pop();
        result[idx] = i - idx;
      }
      s.push(i);
    }

    return result;
  }
};

int main() { return 0; }
