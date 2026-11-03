class Solution {
public:
    int solve(vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp,
              int r1, int c1, int r2) {
        int n = grid.size();
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 < 0 || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1e9;
        }
        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];
        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
        int cnt = grid[r1][c1];
        if (r1 != r2 || c1 != c2) cnt += grid[r2][c2];
        int a = solve(grid, dp, r1+1, c1, r2+1);
        int b = solve(grid, dp, r1+1, c1, r2);
        int c = solve(grid, dp, r1, c1+1, r2+1);
        int d = solve(grid, dp, r1, c1+1, r2);
        return dp[r1][c1][r2] = cnt + max(max(a, b), max(c, d));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, 
        vector<int>(n, -1)));
        return max(0, solve(grid, dp, 0, 0, 0));
    }
};