class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        
        // Step 1: enqueue all border land cells
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) { q.push({i, 0}); grid[i][0] = 0; }
            if (grid[i][n-1] == 1) { q.push({i, n-1}); grid[i][n-1] = 0; }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) { q.push({0, j}); grid[0][j] = 0; }
            if (grid[m-1][j] == 1) { q.push({m-1, j}); grid[m-1][j] = 0; }
        }
        
        // Step 2: BFS inward, sinking all border-connected land
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
        
        // Step 3: count remaining land = enclaves
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                count += grid[i][j];
        
        return count;
    }
};