class Solution {
public:
    unordered_map<int, int> parent;
    
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; 
            x = parent[x];
        }
        return x;
    }
    
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            parent[rx] = ry;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        const int OFFSET = 10001;
        
        for (auto& s : stones) {
            unite(s[0], s[1] + OFFSET);
        }
        
        unordered_set<int> uniqueRoots;
        for (auto& s : stones) {
            uniqueRoots.insert(find(s[0]));
        }
        
        return (int)stones.size() - (int)uniqueRoots.size();
    }
};