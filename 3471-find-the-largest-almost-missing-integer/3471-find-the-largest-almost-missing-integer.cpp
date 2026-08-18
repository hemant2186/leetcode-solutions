class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        
        for (int i = 0; i + k <= n; i++) {
            unordered_set<int> window(nums.begin() + i, nums.begin() + i + k);
            for (int v : window) {
                count[v]++;
            }
        }
        
        int ans = -1;
        for (auto& [v, c] : count) {
            if (c == 1) {
                ans = max(ans, v);
            }
        }
        return ans;
    }
};