class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;
        vector<int> diff(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
        }
        if (k >= sum) return 0;
        sort(diff.rbegin(), diff.rend());
        diff.push_back(0);
        for (int i = 0; i < n; i++) {
            long long count = i + 1;
            long long need = 1LL * (diff[i] - diff[i + 1]) * count;

            if (k >= need) {
                k -= need;
            } else {
                long long reduction = k / count;
                long long remainder = k % count;

                long long level = diff[i] - reduction;
                long long ans = 0;

                for (int j = 0; j <= i; j++) {
                    ans += 1LL * level * level;
                }

                for (int j = 0; j < remainder; j++) {
                    ans -= 2 * level - 1;
                }

                for (int j = i + 1; j < n; j++) {
                    ans += 1LL * diff[j] * diff[j];
                }
                return ans;
            }
        }
        return 0;
    }
};