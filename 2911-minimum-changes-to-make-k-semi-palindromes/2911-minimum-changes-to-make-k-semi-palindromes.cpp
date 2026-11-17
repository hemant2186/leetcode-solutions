
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        int INF = 1e9;
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int l = 0; l < n; l++) {
            for (int len = 2; l + len <= n; len++) {
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int changes = 0;
                    for (int r = 0; r < d; r++) {
                        int left = l + r;
                        int right = l + r + len - d;
                        while (left < right) {
                            if (s[left] != s[right]) changes++;
                            left += d;
                            right -= d;
                        }
                    }
                    cost[l][l + len - 1] = min(cost[l][l + len - 1], changes);
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int j = 1; j <= k; j++) {
            for (int i = 2 * j; i <= n; i++) {
                for (int p = 2 * (j - 1); p <= i - 2; p++) {
                    if (dp[p][j - 1] == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};
