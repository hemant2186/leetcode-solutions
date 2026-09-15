class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int rob=0;
        int norob=0;
        for(int i=start;i<=end;i++){
            int newRob=norob+nums[i];
            int newNoRob=max(norob,rob);
            rob=newRob;
            norob=newNoRob;
        }
        return max(rob,norob);
    }
    int rob(vector<int> &nums){
        int n = nums.size();
        if (n==1) return nums[0];
        return max(solve(nums,0,n-2), solve(nums,1,n-1));
    }
};