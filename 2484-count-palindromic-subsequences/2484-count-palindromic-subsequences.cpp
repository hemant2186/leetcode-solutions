class Solution {
public:
    int countPalindromes(string s) {
        const long long MOD = 1e9 + 7;
        long long leftSingle[10] = {};
        long long rightSingle[10] = {};
        long long leftPairs[10][10] = {};
        long long rightPairs[10][10] = {};
        long long seen[10] = {};

        for (char c : s) rightSingle[c - '0']++;
        for (char c : s) {
            int d = c - '0';
            for (int x = 0; x < 10; x++) {
                rightPairs[x][d] += seen[x];
            }
            seen[d]++;
        }
        long long ans = 0;
        for (char c : s) {
            int d = c - '0';
            rightSingle[d]--;
            for (int x = 0; x < 10; x++) {
                rightPairs[d][x] -= rightSingle[x];
            }
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ans = (ans + leftPairs[a][b] *
                           rightPairs[b][a]) % MOD;
                }
            }
            for (int x = 0; x < 10; x++) {
                leftPairs[x][d] += leftSingle[x];
            }
            leftSingle[d]++;
        }
        return ans;
    }
};