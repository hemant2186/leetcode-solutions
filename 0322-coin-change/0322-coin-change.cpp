class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));
        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                int exc = dp[i + 1][j];
                int inc = INF;
                if (coins[i] <= j) {
                    inc = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(inc, exc);
            }
        }
        return dp[0][amount] >= INF ? -1 : dp[0][amount];
    }
};