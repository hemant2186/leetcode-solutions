class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void solve(int start, string &s,
               vector<string> &temp,
               vector<vector<string>> &ans) {
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {

                temp.push_back(s.substr(start, i - start + 1));

                solve(i + 1, s, temp, ans);

                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(0, s, temp, ans);

        return ans;
    }
};