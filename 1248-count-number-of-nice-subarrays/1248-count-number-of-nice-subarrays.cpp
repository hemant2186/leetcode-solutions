class Solution {
public:
    int atMost(vector<int>& nums, int k) {

        if (k < 0)
            return 0;

        int left = 0;
        int odd = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            odd += nums[right] % 2;

            while (odd > k) {
                odd -= nums[left] % 2;
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};