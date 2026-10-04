class Solution {
public:
    int solve(int r, int c1, int c2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int r2 = r + c1 - c2;
        if (r >= n || c1 >= n || c2 >= n ||
            r2 >= n || r < 0 || c1 < 0 || c2 < 0)
            return -1e9;
        if (grid[r][c1] == -1 || grid[r2][c2] == -1) return -1e9;
        if (r == n - 1 && c1 == n - 1) return grid[r][c1];
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int cherries = 0;
        if (r == r2 && c1 == c2)
            cherries = grid[r][c1];
        else
            cherries = grid[r][c1] + grid[r2][c2];

        int maxi = -1e9;
        maxi = max(maxi, solve(r + 1, c1, c2, grid, dp));
        maxi = max(maxi, solve(r + 1, c1, c2 + 1, grid, dp));
        maxi = max(maxi, solve(r, c1 + 1, c2, grid, dp));
        maxi = max(maxi, solve(r, c1 + 1, c2 + 1, grid, dp));

        return dp[r][c1][c2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n, vector<int>(n, -1))
        );
        int ans = solve(0, 0, 0, grid, dp);
        return max(0, ans);
    }
};