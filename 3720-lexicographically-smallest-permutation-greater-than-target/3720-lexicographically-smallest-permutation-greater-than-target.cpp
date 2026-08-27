class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        
        int resultIndex = -1;
        char resultChar = '\0';
        int savedCnt[26] = {0};
        
        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';
            
            int greaterChar = -1;
            for (int c = t + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    greaterChar = c;
                    break;
                }
            }
            
            if (greaterChar != -1) {
                resultIndex = i;
                resultChar = 'a' + greaterChar;
                memcpy(savedCnt, cnt, sizeof(cnt));
                savedCnt[greaterChar]--;
            }
            
            if (cnt[t] > 0) {
                cnt[t]--;
            } else {
                break;
            }
        }
        
        if (resultIndex == -1) return "";
        string result = target.substr(0, resultIndex);
        result += resultChar;
        
        for (int c = 0; c < 26; c++) {
            result.append(savedCnt[c], 'a' + c);
        }
        
        return result;
    }
};