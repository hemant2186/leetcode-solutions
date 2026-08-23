class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        int s1 = 0, s2 = 0, cnt1 = 0, cnt2 = 0;
        
        for (int i = 0; i < half; ++i) {
            if (num[i] == '?') cnt1++;
            else s1 += num[i] - '0';
        }
        
        for (int i = half; i < n; ++i) {
            if (num[i] == '?') cnt2++;
            else s2 += num[i] - '0';
        }
        
        int totalQ = cnt1 + cnt2;
        
        if (totalQ % 2 == 1) return true;
        return (s1 - s2) != 9 * (cnt2 - cnt1) / 2;
    }
};