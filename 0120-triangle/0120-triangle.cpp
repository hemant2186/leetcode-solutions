class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) dp[n-1][j] = t[n-1][j];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int a = dp[i+1][j];
                int b = dp[i+1][j+1];
                dp[i][j] = t[i][j] + min(a, b);
            }
        }
        return dp[0][0];
    }
};