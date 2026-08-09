class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        
        function<int(int,int)> dp = [&](int i, int M) -> int {
            if (i >= n) return 0;
            if (2 * M >= n - i) {
                return suffixSum[i]; 
            }
            if (memo[i][M] != -1) return memo[i][M];
            
            int best = 0;
            for (int X = 1; X <= 2 * M; X++) {
                if (i + X > n) break;
                int newM = max(M, X);
                int result = suffixSum[i] - dp(i + X, newM);
                best = max(best, result);
            }
            
            memo[i][M] = best;
            return best;
        };
        
        return dp(0, 1);
    }
};