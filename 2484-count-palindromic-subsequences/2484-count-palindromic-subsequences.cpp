class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size(), MOD = 1e9 + 7;
        vector<vector<vector<long long>>> L(n + 1, vector<vector<long long>>(10, vector<long long>(10, 0)));
        vector<vector<vector<long long>>> R(n + 1, vector<vector<long long>>(10, vector<long long>(10, 0)));
        long long freq[10] = {};
        for (int i = 0; i < n; i++) {
            L[i + 1] = L[i];
            int d = s[i] - '0';
            for (int a = 0; a < 10; a++)
                L[i + 1][a][d] += freq[a];
            freq[d]++;
        }
        fill(freq, freq + 10, 0);
        for (int i = n - 1; i >= 0; i--) {
            R[i] = R[i + 1];
            int d = s[i] - '0';
            for (int b = 0; b < 10; b++)
                R[i][d][b] += freq[b];
            freq[d]++;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ans = (ans + L[i][a][b] * R[i + 1][b][a]) % MOD;
                }
            }
        }
        return ans;
    }
};