class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> outDegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            outDegree[i] = graph[i].size();
            for (int neighbor : graph[i]) {
                revGraph[neighbor].push_back(i);
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<bool> isSafe(n, false);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            isSafe[node] = true;
            
            for (int prevNode : revGraph[node]) {
                outDegree[prevNode]--;
                if (outDegree[prevNode] == 0) {
                    q.push(prevNode);
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) {
                result.push_back(i);
            }
        }
        
        return result; 
    }
};