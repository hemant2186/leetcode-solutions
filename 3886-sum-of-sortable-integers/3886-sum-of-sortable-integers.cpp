class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            bool valid = true;
            int prevMax = 0;
            for (int start = 0; start < n; start += k) {
                int mn = INT_MAX, mx = INT_MIN;
                int descents = 0;
                int end = start + k - 1;
                for (int i = start; i <= end; ++i) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                    if (i < end && nums[i] > nums[i + 1]) ++descents;
                }
                if (nums[end] > nums[start]) ++descents;
                if (descents > 1) {
                    valid = false;
                    break;
                }
                if (start > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }
                prevMax = mx;
            }
            if (valid) ans += k;
        }
        return ans;
    }
};