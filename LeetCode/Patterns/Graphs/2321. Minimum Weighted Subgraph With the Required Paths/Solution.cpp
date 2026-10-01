class Solution {
public:
    void dijkstra(int src, vector<vector<pair<int,int>>>& g, vector<long long>& dist) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : g[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> adj(n), radj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            radj[e[1]].push_back({e[0], e[2]});
        }

        long long inf = 1e18;
        vector<long long> a(n, inf), b(n, inf), c(n, inf);
        dijkstra(src1, adj, a);
        dijkstra(src2, adj, b);
        dijkstra(dest, radj, c);

        long long ans = inf;
        for (int i = 0; i < n; i++) {
            if (a[i] == inf || b[i] == inf || c[i] == inf) continue;
            ans = min(ans, a[i] + b[i] + c[i]);
        }
        return ans == inf ? -1 : ans;
    }
};