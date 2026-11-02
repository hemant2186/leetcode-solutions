class Solution {
public:
    int minMoves2(vector<int>& a) {
        int n =a.size();
        sort(a.begin(), a.end());
        int mid = n/2;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(a[i] - a[mid]);
        }
        return ans;
    }
};