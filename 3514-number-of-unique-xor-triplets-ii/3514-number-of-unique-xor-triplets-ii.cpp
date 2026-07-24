class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<int>> dp(4, vector<int>(MAXX, 0));
        dp[0][0] = 1;

        for (int v : nums) {
            auto ndp = dp;

            for (int cnt = 0; cnt <= 3; cnt++) {
                for (int x = 0; x < MAXX; x++) {
                    if (!dp[cnt][x]) continue;

                    // Take 1 copy
                    if (cnt + 1 <= 3)
                        ndp[cnt + 1][x ^ v] = 1;

                    // Take 2 copies (xor unchanged)
                    if (cnt + 2 <= 3)
                        ndp[cnt + 2][x] = 1;

                    // Take 3 copies
                    if (cnt + 3 <= 3)
                        ndp[cnt + 3][x ^ v] = 1;
                }
            }

            dp = move(ndp);
        }

        int ans = 0;
        for (int x = 0; x < MAXX; x++)
            ans += dp[3][x];

        return ans;
    }
};