class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        while (!pq.empty()) {
            auto [curEffort, r, c] = pq.top();
            pq.pop();
            
            if (r == rows-1 && c == cols-1) return curEffort;
            
            if (curEffort > effort[r][c]) continue; 
            
            for (auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int diff = abs(heights[nr][nc] - heights[r][c]);
                    int newEffort = max(curEffort, diff);
                    
                    if (newEffort < effort[nr][nc]) {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }
        
        return 0; 
    }
};