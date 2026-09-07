class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        long long dp = 1;
        vector<long long> last(26, 0);

        for (char ch : s) {
            int c = ch - 'a';
            long long newDp = (2 * dp) % MOD;
            newDp = (newDp - last[c] + MOD) % MOD;

            last[c] = dp;
            dp = newDp;
        }
        return (dp - 1 + MOD) % MOD;
    }
};