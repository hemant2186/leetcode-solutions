class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        vector<int> newParent(n, -1);
        vector<int> last(26, -1);
        struct Event {
            int node;
            bool exit;
            int oldLast;
        };
        stack<Event> st;
        st.push({0, false, -1});
        while (!st.empty()) {
            Event e = st.top();
            st.pop();
            int u = e.node;
            int c = s[u] - 'a';
            if (e.exit) {
                last[c] = e.oldLast;
            } else {
                int old = last[c];
                newParent[u] = (old != -1) ? old : parent[u];
                last[c] = u;
                st.push({u, true, old});
                for (int i = (int)children[u].size() - 1; i >= 0; i--) {
                    st.push({children[u][i], false, -1});
                }
            }
        }
        vector<vector<int>> modified(n);
        for (int i = 1; i < n; i++) {
            modified[newParent[i]].push_back(i);
        }
        vector<int> order;
        stack<int> dfs;
        dfs.push(0);
        while (!dfs.empty()) {
            int u = dfs.top();
            dfs.pop();
            order.push_back(u);
            for (int v : modified[u]) dfs.push(v);
        }
        vector<int> ans(n, 1);
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }
        return ans;
    }
};