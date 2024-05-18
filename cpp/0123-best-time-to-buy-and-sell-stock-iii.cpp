class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i20 = 0, dp_i21 = INT_MIN,
            dp_i10 = 0, dp_i11 = INT_MIN;
        for (const int p : prices) {
            dp_i20 = max(dp_i20, dp_i21 + p);
            dp_i21 = max(dp_i21, dp_i10 - p);
            dp_i10 = max(dp_i10, dp_i11 + p);
            dp_i11 = max(dp_i11, -p);
        }
        return dp_i20;
    }
};
