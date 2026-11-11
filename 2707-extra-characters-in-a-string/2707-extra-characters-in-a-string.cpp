class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        int n = s.size();
        unordered_set<string> dict(d.begin(), d.end());
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i+1];
            for (int j = i; j < n; j++) {
                string word = s.substr(i, j - i + 1);
                if (dict.count(word)) {
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};