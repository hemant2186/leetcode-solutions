class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        if (startColor == color) return image; 
        
        dfs(image, sr, sc, startColor, color);
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int r, int c, int startColor, int newColor) {
        int m = image.size(), n = image[0].size();
        
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != startColor) return;
        
        image[r][c] = newColor;
        
        dfs(image, r + 1, c, startColor, newColor);
        dfs(image, r - 1, c, startColor, newColor);
        dfs(image, r, c + 1, startColor, newColor);
        dfs(image, r, c - 1, startColor, newColor);
    }
};