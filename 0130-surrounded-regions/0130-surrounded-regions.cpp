class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        if (m == 0 || n == 0) return;
        
        queue<pair<int,int>> q;
        
        // Step 1: enqueue all border 'O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') { q.push({i, 0}); board[i][0] = 'S'; }
            if (board[i][n-1] == 'O') { q.push({i, n-1}); board[i][n-1] = 'S'; }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') { q.push({0, j}); board[0][j] = 'S'; }
            if (board[m-1][j] == 'O') { q.push({m-1, j}); board[m-1][j] = 'S'; }
        }
        
        // Step 2: BFS outward, marking connected 'O's as safe
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    board[nr][nc] = 'S';
                    q.push({nr, nc});
                }
            }
        }
        
        // Step 3: flip
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};