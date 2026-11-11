class Solution {
public:
    int solve(int i, int n, string& s, unordered_set<string>& dict, 
    vector<int> &dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = 1 + solve(i + 1, n, s, dict, dp);
        for (int j = i; j < n; j++) {
            string word = s.substr(i, j - i + 1);
            if (dict.count(word)) {
                ans = min(ans, solve(j + 1, n, s, dict, dp));
            }
        }
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& d) {
        int n = s.size();
        unordered_set<string> dict(d.begin(), d.end());
        vector<int> dp(n+1, -1);
        return solve(0, n, s, dict, dp);
    }
};