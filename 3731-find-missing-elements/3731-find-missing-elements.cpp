class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        
        vector<int> result;
        for (int x = lo; x <= hi; x++) {
            if (numSet.find(x) == numSet.end()) {
                result.push_back(x);
            }
        }
        return result;
    }
};