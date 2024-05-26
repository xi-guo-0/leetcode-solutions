#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int cash = 0, hold = -prices[0];
    for (auto price : prices) {
      cash = max(cash, hold + price - fee);
      hold = max(hold, cash - price);
    }
    return cash;
  }
};

int main() {
  vector<int> prices{1, 3, 2, 8, 4, 9};
  int fee = 2;
  Solution solution;
  assert((solution.maxProfit(prices, 2) == 8));
  return 0;
}
