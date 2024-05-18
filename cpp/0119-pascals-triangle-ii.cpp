class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) { return vector<int>(); }
        if (rowIndex == 0) { return vector<int>(1, 1); }
        vector<int> result;
        result.push_back(1);
        int m = rowIndex;
        for (int i = 1; i < m; i++) {
            int n = min(i, m - i);
            long long k = m - n;
            long long c = 1;
            for (long long j = 1; j <= n; j++) {
                c *= (k + j);
                c /= j;
            }
            result.push_back(c);
        }
        result.push_back(1);
        return result;
    }
};
