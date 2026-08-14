class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(26, 0);
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            int c = s[right] - 'a';
            count[c]++;

            while (count[c] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};