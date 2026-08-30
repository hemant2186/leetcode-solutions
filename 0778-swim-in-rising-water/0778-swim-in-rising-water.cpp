class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});
        
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();
            
            if (r == n - 1 && c == n - 1) return d;
            if (d > dist[r][c]) continue; // stale entry
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                
                int newDist = max(d, grid[nr][nc]);
                if (newDist < dist[nr][nc]) {
                    dist[nr][nc] = newDist;
                    pq.push({newDist, nr, nc});
                }
            }
        }
        
        return -1; 
    }
};