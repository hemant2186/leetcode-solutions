class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        if (n == 1) return 1;
        
        vector<vector<int>> directions = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<tuple<int,int,int>> q; 
        
        q.push({0, 0, 1});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();
            
            if (r == n-1 && c == n-1) return dist;
            
            for (auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && 
                    !visited[nr][nc] && grid[nr][nc] == 0) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, dist + 1});
                }
            }
        }
        
        return -1;
    }
};