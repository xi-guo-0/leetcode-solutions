class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        upside_down(matrix);
        transpose(matrix);
    }
    
    void upside_down(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int half_m = matrix.size() / 2;
        for (int i = 0; i < half_m; i++)
            swap(matrix[i], matrix[m - 1 - i]);
    }
    
    void transpose(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) { return; }
        const int m = matrix.size(),
                  n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    
};
