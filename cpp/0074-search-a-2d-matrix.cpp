class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, const int target) {
        if (matrix.empty() || matrix.front().empty()) return false;
        int r = matrix.size() - 1, c = 0;
        while (0 <= r && c < matrix.front().size()) {
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] < target) c++;
            else r--;
        }
        return false;
    }
};
