class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> c(n, -1);
        dfs(c, result, 0);
        return result;
    }

private:
    void dfs(vector<int>& c, vector<vector<string>>& result, int row) {
        const int n = c.size();
        if (row == n) {
            vector<string> one_result;
            for (int i = 0; i < n; i++) {
                string s(n, '.');
                s[c[i]] = 'Q';
                one_result.push_back(s);
            }
            result.push_back(one_result);
            return;
        }
        
        for (int j = 0; j < n; j++) {
            if (is_valid(c, row, j)) {
                c[row] = j;
                dfs(c, result, row + 1);
            }
        }
    }
    
    bool is_valid(const vector<int>& c, int row, int col) {
        for (int i = 0; i < row; i++)
            if (c[i] == col || row - i == abs(c[i] - col))
                return false;
        
        return true;
    }
};
