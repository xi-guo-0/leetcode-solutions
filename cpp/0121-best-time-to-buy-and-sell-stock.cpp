class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int sell = 0, buy = INT_MIN;
        for (const int p : prices) {
            sell = max(sell, buy + p);
            buy = max(buy, -p);
        }
        return sell;
    }
};
