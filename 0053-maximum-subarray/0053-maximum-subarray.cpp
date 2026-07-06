class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0, maxi = LLONG_MIN;

        for(int x : nums){
            sum+=x;
            maxi = max(sum, maxi);
            if (sum < 0) sum = 0;
        }
        return maxi;
    }
};