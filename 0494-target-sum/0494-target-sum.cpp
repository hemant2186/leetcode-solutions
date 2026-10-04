class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int difference) {
        return countPartitions(arr, difference);
    }
    int countPartitions(vector<int>& arr, int difference) {
        int n = arr.size();
        int totalSum = 0;
        for (int value : arr) {
            totalSum += value;
        }
        int remaining = totalSum - difference;
        if (remaining < 0 || remaining % 2 != 0) {
            return 0;
        }
        int target = remaining / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        if (arr[0] == 0) {
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
        }
        if (arr[0] != 0 && arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }
        for (int index = 1; index < n; index++) {
            for (int currentTarget = 0; currentTarget <= target;
                 currentTarget++) {
                int notTake = dp[index - 1][currentTarget];
                int take = 0;
                if (arr[index] <= currentTarget) {
                    take = dp[index - 1][currentTarget - arr[index]];
                }
                dp[index][currentTarget] = (notTake + take);
            }
        }
        return dp[n - 1][target];
    }
};