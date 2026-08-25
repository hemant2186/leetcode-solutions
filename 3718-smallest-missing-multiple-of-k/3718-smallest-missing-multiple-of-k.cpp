class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());
        int m = k;
        while (set.count(m)) {
            m += k;
        }
        return m;
    }
};