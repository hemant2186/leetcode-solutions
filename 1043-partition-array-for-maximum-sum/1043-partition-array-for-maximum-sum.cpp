
class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<vector<int>> &dp) {
        int n = arr.size();
        if (i == n) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int maxi = 0;
        int best = 0;
        for (int j = i; j < min(n, i + k); j++) {
            maxi = max(maxi, arr[j]);
            int len = j - i + 1;
            int cost = (maxi * len) + solve(j + 1, arr, k, dp);
            best = max(best, cost);
        }
        return dp[i][k] = best;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(0, arr, k, dp);
    }
};
