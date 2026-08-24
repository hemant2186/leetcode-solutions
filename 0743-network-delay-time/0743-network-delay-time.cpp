class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            graph[u].push_back({v, w});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        dist[k] = 0;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            if (d > dist[node]) continue; 
            
            for (auto& [nei, w] : graph[node]) {
                if (dist[node] + w < dist[nei]) {
                    dist[nei] = dist[node] + w;
                    pq.push({dist[nei], nei});
                }
            }
        }
        
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; 
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
};