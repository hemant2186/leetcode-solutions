
class Solution {
public:
    string solve(vector<string>& a) {
        int n = a.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = min(a[i].size(), a[j].size()); k > 0; k--) {
                    if (a[i].compare(a[i].size() - k, k, a[j], 0, k) == 0) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
        int total = 1 << n;
        int INF = 1e9;
        vector<vector<int>> dp(total, vector<int>(n, INF));
        vector<vector<int>> parent(total, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = a[i].size();
        }
        for (int mask = 1; mask < total; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int newMask = mask | (1 << j);
                    int cost = a[j].size() - overlap[i][j];
                    if (dp[mask][i] + cost < dp[newMask][j]) {
                        dp[newMask][j] = dp[mask][i] + cost;
                        parent[newMask][j] = i;
                    }
                }
            }
        }
        int fullMask = total - 1;
        int last = 0;
        for (int i = 1; i < n; i++) {
            if (dp[fullMask][i] < dp[fullMask][last]) last = i;
        }
        vector<int> path;
        int mask = fullMask;
        while (last != -1) {
            path.push_back(last);
            int prev = parent[mask][last];
            mask ^= (1 << last);
            last = prev;
        }
        reverse(path.begin(), path.end());
        string ans = a[path[0]];
        for (int i = 1; i < path.size(); i++) {
            int prev = path[i - 1];
            int curr = path[i];
            ans += a[curr].substr(overlap[prev][curr]);
        }
        return ans;
    }
    string shortestSuperstring(vector<string>& words) {
        vector<string> a;
        for (string& s : words) {
            if (find(a.begin(), a.end(), s) == a.end())
                a.push_back(s);
        }
        vector<string> filtered;
        for (int i = 0; i < a.size(); i++) {
            bool contained = false;
            for (int j = 0; j < a.size(); j++) {
                if (i != j && a[j].find(a[i]) != string::npos) {
                    contained = true;
                    break;
                }
            }
            if (!contained) filtered.push_back(a[i]);
        }
        return solve(filtered);
    }
};
