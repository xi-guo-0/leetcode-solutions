class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 ||
            obstacleGrid[0].size() == 0 ||
            obstacleGrid[0][0] == 1 ||
            obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]) {
            return 0;
        }
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        
        vector<long long> f(n, 0);
        f[0] = obstacleGrid[0][0] ? 0 : 1;
        
        for (int i = 0; i < m; i++) {
            f[0] = f[0] == 0 ? 0 : (obstacleGrid[i][0] ? 0 : 1);
            for (int j = 1; j < n; j++)
                f[j] = obstacleGrid[i][j] ? 0 : (f[j] + f[j - 1]);
        }
        return f[n - 1];
    }
};
