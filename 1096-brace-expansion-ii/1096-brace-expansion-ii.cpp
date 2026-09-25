class Solution {
public:
    using Set = set<string>;
    Set combine(const Set& A, const Set& B) {
        Set res;
        for (const string& a : A) {
            for (const string& b : B) {
                res.insert(a + b);
            }
        }
        return res;
    }

    Set parse(const string& s, int& i) {
        Set res;
        Set cur;

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                res.insert(cur.begin(), cur.end());
                cur.clear();
                i++;
            } 
            else {
                Set part;

                if (s[i] == '{') {
                    i++; 
                    part = parse(s, i);
                    i++; 
                } 
                else {
                    part.insert(string(1, s[i]));
                    i++;
                }
                if (cur.empty()) {
                    cur = part;
                } else {
                    cur = combine(cur, part);
                }
            }
        }
        res.insert(cur.begin(), cur.end());
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        Set ans = parse(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};