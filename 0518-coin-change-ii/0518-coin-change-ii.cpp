class Solution {
public:
    int change(int value, vector<int>& a) {
        int n = a.size();
        vector<vector<long>> dp(n, vector<long>(value + 1, -1));
        return f(n - 1, value, a, dp);
    }

    long f(int ind, int T, vector<int>& a, vector<vector<long>>& dp) {
        if (ind == 0) {
            return (T % a[0] == 0);
        }
        if (dp[ind][T] != -1)
            return dp[ind][T];

        long notTake = f(ind - 1, T, a, dp);
        long take = 0;
        if (a[ind] <= T)
            take = f(ind, T - a[ind], a, dp);

        return dp[ind][T] = take + notTake;
    }
};