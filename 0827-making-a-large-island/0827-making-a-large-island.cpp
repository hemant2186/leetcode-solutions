class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> id(n, vector<int>(n, 0));
        unordered_map<int, int> islandSize;
        int currentId = 2; 
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && id[i][j] == 0) {
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    id[i][j] = currentId;
                    int size = 0;
                    
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        size++;
                        
                        for (auto& dir : dirs) {
                            int nr = r + dir[0];
                            int nc = c + dir[1];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n 
                                && grid[nr][nc] == 1 && id[nr][nc] == 0) {
                                id[nr][nc] = currentId;
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    islandSize[currentId] = size;
                    currentId++;
                }
            }
        }
        
        int result = 0;
        for (auto& [key, sz] : islandSize) {
            result = max(result, sz);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborIds;
                    for (auto& dir : dirs) {
                        int nr = i + dir[0];
                        int nc = j + dir[1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            neighborIds.insert(id[nr][nc]);
                        }
                    }
                    
                    int total = 1; 
                    for (int nid : neighborIds) {
                        total += islandSize[nid];
                    }
                    
                    result = max(result, total);
                }
            }
        }
        
        return result;
    }
};