class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n2 = nums.size();
        int n = n2 / 2;
        vector<vector<long long>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); ++mask) {
            long long sumL = 0, sumR = 0;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sumL += nums[i];
                    sumR += nums[i + n];
                    cnt++;
                }
            }

            left[cnt].push_back(sumL);
            right[cnt].push_back(sumR);
        }

        for (int k = 0; k <= n; ++k) {
            sort(right[k].begin(), right[k].end());
        }

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = LLONG_MAX;

        for (int k = 0; k <= n; ++k) {
            for (long long sumL : left[k]) {
                int need = n - k;
                long double target = (long double)total / 2.0 - sumL;

                auto it = lower_bound(right[need].begin(),
                                      right[need].end(),
                                      target);

                if (it != right[need].end()) {
                    long long selected = sumL + *it;
                    ans = min(ans, llabs(2 * selected - total));
                }

                if (it != right[need].begin()) {
                    --it;
                    long long selected = sumL + *it;
                    ans = min(ans, llabs(2 * selected - total));
                }
            }
        }
        return (int)ans;
    }
};