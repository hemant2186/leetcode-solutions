class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;
        if (n == 2) return true;

        vector<unordered_set<int>> dp(n);
        dp[1].insert(1);

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[stones[i]] = i;
        }

        for (int i = 1; i < n; i++) {

            for (int k : dp[i]) {
                for (int nextJump = k - 1;
                     nextJump <= k + 1;
                     nextJump++) {

                    if (nextJump <= 0) continue;

                    int nextPos = stones[i] + nextJump;

                    if (pos.count(nextPos)) {
                        int nextIndex = pos[nextPos];

                        if (nextIndex == n - 1)
                            return true;

                        dp[nextIndex].insert(nextJump);
                    }
                }
            }
        }

        return false;
    }
};