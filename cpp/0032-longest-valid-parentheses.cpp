class Solution {
public:
    int longestValidParentheses(const string& s) {
        vector<int> dp(s.size(), 0);
        int ret = 0;
        for (int i = s.size() - 2; i >= 0; i--) {
            int match = i + dp[i + 1] + 1;
            if (s[i] == '(' && match < s.size() && s[match] == ')') {
                dp[i] = dp[i + 1] + 2;
                if (match + 1 < s.size())
                    dp[i] += dp[match + 1];
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
