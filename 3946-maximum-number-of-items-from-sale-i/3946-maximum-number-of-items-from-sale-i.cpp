class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            int bonus = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) bonus++;
            }
            a.push_back({items[i][1], bonus + 1});
        }
        sort(a.rbegin(), a.rend());
        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;
        int ans = 0;
        int i = 0;
        while (i < n) {
            int p = a[i].first;
            vector<int> cur(budget + 1, NEG);
            int j = i;
            while (j < n && a[j].first == p) {
                int v = a[j].second;
                for (int c = budget; c >= p; c--) {
                    if (dp[c - p] != NEG) {
                        cur[c] = max(cur[c], dp[c - p] + v);
                    }
                    if (cur[c - p] != NEG) {
                        cur[c] = max(cur[c], cur[c - p] + v);
                    }
                }
                j++;
            }
            for (int c = 0; c <= budget; c++) {
                if (cur[c] != NEG) {
                    ans = max(ans, cur[c] + (budget - c) / p);
                    dp[c] = max(dp[c], cur[c]);
                }
            }
            i = j;
        }
        return ans;
    }
};