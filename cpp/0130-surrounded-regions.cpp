class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        
        const int m = board.size();
        const int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            bfs(board, i, 0);
            bfs(board, i, n - 1);
        }
        
        for (int j = 0; j < n; j++) {
            bfs(board, 0, j);
            bfs(board, m - 1, j);
        }
        
        for (auto& line : board) {
            for (auto& letter : line) {
                if (letter == 'O')
                    letter = 'X';
                else if (letter == placeholder)
                    letter = 'O';
            }
        }
    }
    
private:
    static const char placeholder = '+';
    
    void bfs(vector<vector<char>>& board, int i, int j) {
        typedef pair<int, int> state_t;
        queue<state_t> q;
        const int m = board.size();
        const int n = board[0].size();
        
        auto state_is_valid = [&](const state_t& s) {
            const int x = s.first;
            const int y = s.second;
            return 0 <= x && x < m && 0 <= y && y < n && board[x][y] == 'O';
        };
        
        auto state_extend = [&](const state_t& s) {
            vector<state_t> result;
            const int x = s.first;
            const int y = s.second;
            
            const state_t new_states[4] = {{x-1, y},
                                           {x+1, y},
                                           {x, y-1},
                                           {x, y+1}};
            for (auto state : new_states) {
                if (state_is_valid(state)) {
                    board[state.first][state.second] = placeholder;
                    result.push_back(state);
                }
            }
            return result;
        };
        
        state_t start(i, j);
        if (state_is_valid(start)) {
            board[i][j] = placeholder;
            q.push(start);
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            auto new_states = state_extend(cur);
            for (auto s : new_states)
                q.push(s);
        }
    }
};
