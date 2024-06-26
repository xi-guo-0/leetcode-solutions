class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int sold = 0, rest = 0, hold = INT_MIN;
    for (int p : prices) {
      int pre_sold = sold;
      sold = hold + p;
      hold = max(hold, rest - p);
      rest = max(rest, pre_sold);
    }
    return max(sold, rest);
  }
};
