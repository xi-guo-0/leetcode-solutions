class Solution {
public:
  int maxProfit(const int k, const vector<int> &prices) {
    if (prices.size() / 2 <= k) {
      int profit = 0;
      for (int i = 1; i < prices.size(); i++)
        profit += max(0, prices[i] - prices[i - 1]);
      return profit;
    }
    vector<int> dp_ik0(k + 1, 0);
    vector<int> dp_ik1(k + 1, INT_MIN);
    for (const int p : prices) {
      for (int j = k; 0 < j; j--) {
        dp_ik0[j] = max(dp_ik0[j], dp_ik1[j] + p);
        dp_ik1[j] = max(dp_ik1[j], dp_ik0[j - 1] - p);
      }
    }
    return dp_ik0[k];
  }
};
