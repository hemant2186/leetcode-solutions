class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n = a.size();
        a.push_back(1);
        a.insert(a.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int maxi = INT_MIN;
                for (int idx = i; idx <= j; idx++) {
                    int cost = a[i - 1] * a[idx] * a[j + 1] + dp[i][idx - 1]
                             + dp[idx + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};