class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) totalSum += stones[i];
        int target = totalSum / 2;
        
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (stones[0] <= target) dp[0][stones[0]] = true;
        for (int ind = 1; ind < n; ind++) {
            for (int sum = 1; sum <= target; sum++) {
                bool notTake = dp[ind - 1][sum];
                bool take = false;
                if (stones[ind] <= sum) {
                    take = dp[ind - 1][sum - stones[ind]];
                }
                dp[ind][sum] = take || notTake;
            }
        }
        int s1 = 0;
        for (int sum = target; sum >= 0; sum--) {
            if (dp[n - 1][sum]) {
                s1 = sum;
                break;
            }
        }
        int s2 = totalSum - s1;
        return abs(s2 - s1);
    }
};