class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int L = m + n - 1;

        if (L % 2 == 1) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        vector<vector<bool>> dp(n, vector<bool>(L + 1, false));
        dp[0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int delta = (grid[i][j] == '(' ? 1 : -1);
                vector<bool> cur(L + 1, false);

                if (i > 0) {
                    for (int bal = 0; bal <= L; bal++) {
                        if (dp[j][bal]) {
                            int newBal = bal + delta;
                            if (newBal >= 0 && newBal <= L)
                                cur[newBal] = true;
                        }
                    }
                }
                if (j > 0) {
                    for (int bal = 0; bal <= L; bal++) {
                        if (dp[j - 1][bal]) {
                            int newBal = bal + delta;
                            if (newBal >= 0 && newBal <= L)
                                cur[newBal] = true;
                        }
                    }
                }
                dp[j] = cur;
            }
        }
        return dp[n - 1][0];
    }
};