class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;
            vector<long long> ndp(k, 0);
            ndp[val]++;

            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                int newRem = (r * val) % k;
                ndp[newRem] += dp[r];
            }
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }
            dp = ndp;
        }
        return ans;
    }
};