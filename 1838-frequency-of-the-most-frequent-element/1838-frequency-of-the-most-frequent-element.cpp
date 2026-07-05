class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;   // sum of elements in current window
        int left = 0;
        int ans = 1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // cost to make all elements in window equal to nums[right]
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
