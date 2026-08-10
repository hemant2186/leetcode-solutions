class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        if (startColor == color) return image;
        
        int m = image.size(), n = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == startColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        
        return image;
    }
};