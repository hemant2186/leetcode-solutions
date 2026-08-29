class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; 
            x = parent[x];
        }
        return x;
    }
    
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) parent[rx] = ry;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        unordered_map<string, int> emailToAccount; 
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (int)accounts[i].size(); j++) {
                string& email = accounts[i][j];
                if (emailToAccount.find(email) != emailToAccount.end()) {
                    unite(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }
        
        unordered_map<int, set<string>> rootToEmails; 
        for (auto& [email, idx] : emailToAccount) {
            int root = find(idx);
            rootToEmails[root].insert(email);
        }
        
        vector<vector<string>> result;
        for (auto& [root, emails] : rootToEmails) {
            vector<string> account;
            account.push_back(accounts[root][0]); 
            for (const string& email : emails) {
                account.push_back(email);
            }
            result.push_back(account);
        }
        
        return result;
    }
};