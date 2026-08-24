class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, 
        greater<pair<long long,int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        long long mod = 1e9 + 7;
        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue; 

            for (auto it : adj[node]) {
                int adjNode = it.first;
                long long edW = it.second;
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return (int)(ways[n-1] % mod);
    }
};