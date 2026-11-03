class Solution {
public:
    int minMoves(vector<int>& a) {
        int n = a.size();
        int maxi = *max_element(a.begin(), a.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            while (a[i] < maxi){
                a[i]++;
                ans++;
            }
        }
        return ans;
    }
};