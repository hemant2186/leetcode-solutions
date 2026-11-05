
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            int maxi = 0;
            int best = 0;
            for (int j = i; j < min(n, i + k); j++) {
                maxi = max(maxi, arr[j]);
                int len = j - i + 1;
                int cost = (maxi * len) + dp[j + 1][k];
                best = max(best, cost);
            }
            dp[i][k] = best;
        }
        return dp[0][k];
    }
};
