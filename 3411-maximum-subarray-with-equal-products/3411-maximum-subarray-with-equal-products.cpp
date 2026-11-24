class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = l / gcd(l, (long long)nums[j]) * nums[j];
                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                } else if (prod > g * l) {
                    break;
                }
            }
        }
        return ans;
    }
};