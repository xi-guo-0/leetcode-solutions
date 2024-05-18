class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) { return vector<vector<int>>(); }
        vector<vector<int>> result(n, vector<int>(n, 0));
        int num = 1;
        int layer = 0;
        while (n > 0) {
            int end = n - layer - 1;
            if (n / 2 == layer)
                break;
            for (int j = layer; j < end; j++)
                result[layer][j] = num++;
            for (int i = layer; i < end; i++)
                result[i][end] = num++;
            for (int j = end; layer < j; j--)
                result[end][j] = num++;
            for (int i = end; layer < i; i--)
                result[i][layer] = num++;
            layer++;
        }
        if (n % 2)
            result[n/2][n/2] = num;
        return result;
    }
};
