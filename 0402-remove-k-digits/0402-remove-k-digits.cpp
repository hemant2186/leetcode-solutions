class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }
        while (k > 0) {
            st.pop_back();
            k--;
        }

        string ans;
        bool leadingZero = true;

        for (char c : st) {
            if (leadingZero && c == '0')
                continue;

            leadingZero = false;
            ans += c;
        }

        return ans.empty() ? "0" : ans;
    }
};