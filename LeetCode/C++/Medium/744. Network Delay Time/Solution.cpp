class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& t : times) adj[t[0]].push_back({t[1], t[2]});

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        dist[k] = 0;
        pq.push({0, k});
        int mx = 0, cnt = 0;

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();
            if (t > dist[u]) continue;
            mx = max(mx, t);
            cnt++;
            for (auto [v, w] : adj[u]) {
                if (t + w < dist[v]) {
                    dist[v] = t + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return cnt == n ? mx : -1;
    }
};