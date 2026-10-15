class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);
        prev[0] = true;
        for (int i = 1; i <= n; i++) {
            cur[0] = prev[0] && (p[i - 1] == '*');
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] ||
                    p[i - 1] == '?') {
                    cur[j] = prev[j - 1];
                }
                else if (p[i - 1] == '*') {
                    cur[j] = prev[j] || cur[j - 1];
                }
                else {
                    cur[j] = false;
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};