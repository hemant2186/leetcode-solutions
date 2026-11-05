
class Solution {
public:
    int solve(int i, int n, vector<vector<bool>>& pal, vector<int>& dp) {
        if (i == n) return -1;
        if (dp[i] != -3) return dp[i];
        int mini = INT_MAX;
        for (int j = i; j < n; j++) {
            if (pal[i][j]) {
                int cost = 1 + solve(j + 1, n, pal, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
        vector<int> dp(n, -3);
        return solve(0, n, pal, dp);
    }
};
