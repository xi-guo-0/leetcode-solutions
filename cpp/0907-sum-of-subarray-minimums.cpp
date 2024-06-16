#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int sumSubarrayMins(vector<int> const &arr) {
    stack<int> stk;
    vector<int> sum(arr);
    for (int i = 0; i < arr.size(); ++i) {
      while (!stk.empty() && arr[i] <= arr[stk.top()]) {
        stk.pop();
      }
      if (stk.empty()) {
        sum[i] = arr[i] * (i + 1);
      } else {
        sum[i] = sum[stk.top()] + arr[i] * (i - stk.top());
      }
      sum[i] %= M;
      stk.push(i);
    }
    int ans = 0;
    for (int x : sum) {
      ans = (ans + x) % M;
    }
    return ans;
  }

private:
  static constexpr int M = 1000000007;
};

int main() { return 0; }
