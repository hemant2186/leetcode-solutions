
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        int l = logs.size();
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        vector<pair<int, int>> sorQue;
        for (int i = 0; i < m; i++) sorQue.push_back({queries[i], i});
        sort(sorQue.begin(), sorQue.end());
        vector<int> freq(n + 1, 0);
        vector<int> ans(m);
        int left = 0, right = 0;
        int active = 0;
        for (auto &[q, idx] : sorQue) {
            while (right < l && logs[right][1] <= q) {
                int server = logs[right][0];
                if (freq[server] == 0) active++;
                freq[server]++;
                right++;
            }
            int start = q - x;
            while (left < right && logs[left][1] < start) {
                int server = logs[left][0];
                freq[server]--;
                if (freq[server] == 0) active--;
                left++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};
