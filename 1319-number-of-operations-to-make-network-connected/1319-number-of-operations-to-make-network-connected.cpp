class Solution {
public:
    vector<int> parent, rank_;
    
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; 
            x = parent[x];
        }
        return x;
    }
    
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
        return true;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((int)connections.size() < n - 1) return -1;
        
        parent.resize(n);
        rank_.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        int components = n;
        for (auto& c : connections) {
            if (unite(c[0], c[1])) {
                components--;
            }
        }
        
        return components - 1;
    }
};