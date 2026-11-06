class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char c : expression) {
            if (c == ',') continue;
            if (c != ')') st.push(c);
            else {
                bool hasTrue = false;
                bool hasFalse = false;
                while (st.top() != '(') {
                    char ch = st.top();
                    st.pop();
                    if (ch == 't') hasTrue = true;
                    else hasFalse = true;
                }
                st.pop();
                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                }
                else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                }
                else if (op == '|') {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};