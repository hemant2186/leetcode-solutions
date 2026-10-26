class Solution {
public:
    int dis(vector<vector<int>>& d, vector<vector<int>>& dp, int i, int j) {
        int n = d.size();
        int m = d[0].size();
        if (i == n - 1 && j == m - 1) return max(1, 1 - d[i][j]);
        if (dp[i][j] != -1) return dp[i][j];
        int right = INT_MAX;
        int down = INT_MAX;;
        if (j + 1 < m) right = dis(d, dp, i, j + 1);
        if (i + 1 < n) down = dis(d, dp, i + 1, j);
        int need = min(right, down) - d[i][j];
        return dp[i][j] = max(1, need);
    }
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n = d.size();
        int m = d[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dis(d, dp, 0, 0);
    }
};