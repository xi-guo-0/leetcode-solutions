class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return vector<int>();
        } 
        if (matrix.size() == 1) {
            return matrix[0];
        }
        if (matrix[0].size() == 1) {
            vector<int> result;
            for (int i = 0; i < matrix.size(); i++)
                result.push_back(matrix[i][0]);
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int l = min(m, n);
        int li = m;
        int lj = n;
        vector<int> result;
        for (int frame = 0; frame < l / 2; frame++) {
            for (int j = frame; j < lj - 1; j++)
                result.push_back(matrix[frame][j]);
            for (int i = frame; i < li - 1; i++)
                result.push_back(matrix[i][lj - 1]);
            for (int j = lj - 1; frame < j; j--)
                result.push_back(matrix[li - 1][j]);
            for (int i = li - 1; frame < i; i--)
                result.push_back(matrix[i][frame]);
            li--;
            lj--;
        }
        if (m <= n && m & 0x1) {
            for (int j = m / 2; j < lj; j++)
                result.push_back(matrix[m/2][j]);
        } else if (n & 0x1) {
            for (int i = n / 2; i < li; i++)
                result.push_back(matrix[i][n/2]);
        }
        return result;
    }
};
