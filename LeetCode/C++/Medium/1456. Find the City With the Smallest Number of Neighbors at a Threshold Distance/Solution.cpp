class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int small = n, city = -1;
        for (int src = 0; src < n; src++) {
            vector<int> dist(n, INF);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u]) continue;
                for (auto [v, w] : adj[u]) {
                    if (d + w < dist[v]) {
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            int count = 0;
            for (int j = 0; j < n; j++)
                if (j != src && dist[j] <= distanceThreshold) count++;

            if (count <= small) {
                small = count;
                city = src;
            }
        }
        return city;
    }
};