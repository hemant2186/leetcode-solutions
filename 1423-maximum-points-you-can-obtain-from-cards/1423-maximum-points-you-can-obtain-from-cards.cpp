class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int curr = 0;

        for (int i = 0; i < k; i++)
            curr += cardPoints[i];

        int ans = curr;

        int right = n - 1;


        for (int left = k - 1; left >= 0; left--) {
            curr -= cardPoints[left];
            curr += cardPoints[right--];
            ans = max(ans, curr);
        }

        return ans;
    }
};