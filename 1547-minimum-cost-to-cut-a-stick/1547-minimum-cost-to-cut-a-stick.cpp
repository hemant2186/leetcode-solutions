
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));
        for(int i=len;i>=1;i--){
            for(int j=i;j<=len;j++){
                int mini = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k-1]
                            + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][len];
    }
};
