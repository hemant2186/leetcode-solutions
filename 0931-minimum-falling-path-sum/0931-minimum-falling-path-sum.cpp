class Solution {
public:
    int solve(vector<vector<int>>& a, vector<vector<int>>& dp, int i, int j) {
        int n = a.size();
        int m = a[0].size();
        if (j < 0 || j >= m) return 1e9;
        if (i == n - 1) return a[i][j];
        if (dp[i][j] != INT_MAX) return dp[i][j];
        int down = solve(a, dp, i + 1, j);
        int left = solve(a, dp, i + 1, j - 1);
        int right = solve(a, dp, i + 1, j + 1);
        return dp[i][j] = a[i][j] + min(down, min(left, right));
    }
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, solve(a, dp, 0, j));
        }
        return ans;
    }
};