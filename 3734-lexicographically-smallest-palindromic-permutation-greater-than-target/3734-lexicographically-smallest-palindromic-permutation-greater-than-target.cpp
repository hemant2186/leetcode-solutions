class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 != 0) { oddCount++; oddChar = i; }
        }
        if (n % 2 == 0) {
            if (oddCount != 0) return "";
        } else {
            if (oddCount != 1) return "";
        }

        char midChar = (n % 2 == 1) ? char('a' + oddChar) : '\0';
        vector<int> halfCnt(26, 0);
        for (int i = 0; i < 26; i++) halfCnt[i] = cnt[i] / 2;

        int h = n / 2;
        string targetHalf = target.substr(0, h);
        vector<int> cur = halfCnt;
        int L = 0;
        for (int i = 0; i < h; i++) {
            int c = targetHalf[i] - 'a';
            if (cur[c] > 0) {
                cur[c]--;
                L = i + 1;
            } else {
                break;
            }
        }

        string ans = "";
        if (L == h) {
            string full = buildFull(targetHalf, midChar, n);
            if (full > target) ans = full;
        }

        if (ans.empty()) {
            vector<int> curCounts = cur; 
            for (int i = L; i >= 0; i--) {
                if (i < h) {
                    int tChar = targetHalf[i] - 'a';
                    int pick = -1;
                    for (int c = tChar + 1; c < 26; c++) {
                        if (curCounts[c] > 0) { pick = c; break; }
                    }
                    if (pick != -1) {
                        string half = targetHalf.substr(0, i);
                        half += char('a' + pick);
                        vector<int> rem = curCounts;
                        rem[pick]--;
                        for (int c = 0; c < 26; c++)
                            for (int k = 0; k < rem[c]; k++)
                                half += char('a' + c);
                        ans = buildFull(half, midChar, n);
                        break;
                    }
                }
                if (i > 0) {
                    int prevChar = targetHalf[i - 1] - 'a';
                    curCounts[prevChar]++;
                }
            }
        }

        return ans;
    }

private:
    string buildFull(const string& half, char midChar, int n) {
        string full = half;
        if (n % 2 == 1) full += midChar;
        for (int i = (int)half.size() - 1; i >= 0; i--) full += half[i];
        return full;
    }
};