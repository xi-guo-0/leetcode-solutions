#include <utility>
#include <vector>

using namespace std;

class StockSpanner {
public:
  vector<pair<int, int>> s;

  int next(int price) {
    int c = 1;
    while (!s.empty() && s.back().first <= price)
      c += s.back().second, s.pop_back();
    s.emplace_back(price, c);
    return c;
  }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main() { return 0; }
