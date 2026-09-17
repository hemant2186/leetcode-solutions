class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        vector<int> dp(n, INF);

        int left = 0;
        long long sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left++];
            }
            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && dp[left - 1] != INF) {
                    ans = min(ans, dp[left - 1] + len);
                }
                if (right == 0)
                    dp[right] = len;
                else
                    dp[right] = min(dp[right - 1], len);
            } else {
                if (right > 0)
                    dp[right] = dp[right - 1];
            }
        }
        return ans == INF ? -1 : ans;
    }
};