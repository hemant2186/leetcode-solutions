class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            i++;
        }
        
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += nums[j];
        }
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int x = sum;
        while (numSet.count(x)) {
            x++;
        }
        
        return x;
    }
};