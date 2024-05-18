class Solution {
public:
    bool exist(const vector<vector<char>>& board, const string& word) {
        if (board.empty() || board[0].empty()) { return word.empty(); }
        else if (word.empty()) { return true; }
        set<int> s;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word.front()) {
                    s.insert(board[0].size() * i + j);
                    if (dfs(board, word, 0, i, j, s)) 
                        return true;
                    s.erase(board[0].size() * i + j);
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(const vector<vector<char>>& board, const string& word, const int k, const int r, const int c, set<int>& s) {
        printf("%c %d ", board[r][c], k);
        if (k + 1 == word.size()) { return true; }
        const int dr[] = {-1, 0, 1, 0};
        const int dc[] = { 0, -1,0, 1};
        bool res = false;
        for (int i = 0; i < 4; i++) {
            const int nr = r + dr[i];
            const int nc = c + dc[i];
            const int p = board[0].size() * nr + nc;
            if (0 <= nr && nr < board.size() && 0 <= nc && nc < board[0].size() && board[nr][nc] == word[k + 1] && !s.count(p)) {
                s.insert(p);
                res = res || dfs(board, word, k + 1, nr, nc, s);
                s.erase(p);
                if (res) return true;
            }
        }
        return res;
    }
};
