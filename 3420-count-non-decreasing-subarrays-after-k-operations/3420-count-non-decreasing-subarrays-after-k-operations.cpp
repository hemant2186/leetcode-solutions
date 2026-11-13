class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        vector<int> nxt(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) nxt[i] = st.top();
            st.push(i);
        }
        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];
                up[j][i] = up[j - 1][mid];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
            }
        }
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        auto getCost = [&](int l, int r) -> long long {
            long long maxSum = 0;
            int p = l;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][p] <= r) {
                    maxSum += sum[j][p];
                    p = up[j][p];
                }
            }
            maxSum += 1LL * nums[p] * (r - p + 1);
            return maxSum - (pref[r + 1] - pref[l]);
        };
        long long ans = 0;
        for (int l = 0; l < n; l++) {
            int low = l, high = n - 1;
            int best = l - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (getCost(l, mid) <= k) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans += best - l + 1;
        }
        return ans;
    }
};