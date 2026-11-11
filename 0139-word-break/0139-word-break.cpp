class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        int n = s.size();
        unordered_set<string> dict(d.begin(), d.end());
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                string word = s.substr(i, j - i + 1);
                    if (dict.count(word) && dp[j + 1]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[0];
        }
    };