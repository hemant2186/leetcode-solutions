
class Solution {
public:
    int f(vector<int>& a, vector<vector<int>>& dp, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for (int idx = i; idx <= j; idx++) {
            int cost = a[i-1] * a[idx] * a[j+1] + f(a, dp, i, idx-1)
                     + f(a, dp, idx+1, j);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& a) {
        int n = a.size();
        a.push_back(1);
        a.insert(a.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(a, dp, 1, n);
    }
};
