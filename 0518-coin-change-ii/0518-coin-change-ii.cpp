class Solution {
public:
int solve(vector<int> &coins, vector<vector<int>> &dp, int amount, int i){
    int n = coins.size();
    if (amount == 0) return 1;
    if (amount < 0) return 0;
    if (i == n) return 0;
    if (dp[i][amount] != -1) return dp[i][amount];
    int exc = solve(coins, dp, amount, i+1);
    int inc = 0;
    if (coins[i] <= amount){
        inc = solve(coins, dp, amount - coins[i], i);
    }
    return dp[i][amount] = inc + exc;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1 , -1));
        return solve(coins, dp, amount, 0);
    }
};