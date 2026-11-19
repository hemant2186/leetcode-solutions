class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        vector<int> small(3, INT_MAX);
        vector<int> large(3, INT_MIN);
        for (int x : nums) {
            if (x <= small[0]) {
                small[2] = small[1];
                small[1] = small[0];
                small[0] = x;
            }
            else if (x <= small[1]) {
                small[2] = small[1];
                small[1] = x;
            }
            else if (x <= small[2]) {
                small[2] = x;
            }
            if (x >= large[0]) {
                large[2] = large[1];
                large[1] = large[0];
                large[0] = x;
            }
            else if (x >= large[1]) {
                large[2] = large[1];
                large[1] = x;
            }
            else if (x >= large[2]) {
                large[2] = x;
            }
        }
        return min({
            large[0] - small[2],
            large[1] - small[1],
            large[2] - small[0]
        });
    }
};