
class Solution {
    int INF = 1e9;
    vector<vector<int>> getCost(string& s) {
        int n = s.size();
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
                            if (s[left] != s[right])
                                changes++;
                            left += d;
                            right -= d;
                        }
                    }
                    cost[l][l + len - 1] = min(cost[l][l + len - 1], changes);
                }
            }
        }
        return cost;
    }
    int solve(int i, int parts, vector<vector<int>>& cost,
              vector<vector<int>>& dp) {
        if (parts == 0) return i == 0 ? 0 : INF;
        if (i < 2 * parts) return INF;
        if (dp[i][parts] != -1) return dp[i][parts];
        int ans = INF;
        for (int p = 2 * (parts - 1); p <= i - 2; p++) {
            int prev = solve(p, parts - 1, cost, dp);
            if (prev != INF) {
                ans = min(ans, prev + cost[p][i - 1]);
            }
        }
        return dp[i][parts] = ans;
    }
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        auto cost = getCost(s);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(n, k, cost, dp);
    }
};
