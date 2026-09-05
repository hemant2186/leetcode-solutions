class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int rob=0;
        int norob=0;
        for(int i=0;i<n;i++){
            int newRob=norob+nums[i];
            int newNoRob=max(norob,rob);
            rob=newRob;
            norob=newNoRob;
        }
        return max(rob,norob);
    }
};