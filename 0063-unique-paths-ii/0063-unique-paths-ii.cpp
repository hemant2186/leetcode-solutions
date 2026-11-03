class Solution {
public:
    int solve(vector<vector<int>>& a, vector<vector<int>>& dp, int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (a[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int up = solve(a, dp, i-1, j);
        int left = solve(a, dp, i, j-1);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(a, dp, m-1, n-1);
    }
};