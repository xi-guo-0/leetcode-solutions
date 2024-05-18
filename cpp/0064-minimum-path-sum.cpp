class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) { return 0; }
        int m = grid.size();
        int n = grid[0].size();
        int cost[m][n];
        for (int j = 0, sum = 0; j < n; j++) {
            sum += grid[0][j];
            cost[0][j] = sum;
        }
        for (int i = 0, sum = 0; i < m; i++) {
            sum += grid[i][0];
            cost[i][0] = sum;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cost[i][j] = grid[i][j] + std::min(cost[i - 1][j], cost[i][j - 1]);
            }
        }
        return cost[m - 1][n - 1];
    }
};
