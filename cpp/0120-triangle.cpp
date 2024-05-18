class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>& t = triangle;
        for (int i = 1; i < t.size(); ++i) {
            t[i][0] += t[i - 1][0];
            t[i][t[i].size() - 1] += t[i - 1][t[i].size() - 2];
            for (int j = 1; j + 1 < t[i].size(); ++j) {
                t[i][j] += min(t[i - 1][j - 1], t[i - 1][j]);
            }
        }
        int b = t.size() - 1;
        int ans = t[b][0];
        for (int j = 1; j < t[b].size(); ++j) {
            ans = min(ans, t[b][j]);
        }
        return ans;
    }
};
