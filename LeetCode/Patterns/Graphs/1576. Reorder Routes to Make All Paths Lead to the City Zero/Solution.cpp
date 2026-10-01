class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>> adj(n);
        for (auto& c : connections) {
            adj[c[0]].push_back({c[1], true});   // original direction
            adj[c[1]].push_back({c[0], false});  // reverse entry
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, awayFromU] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    if (awayFromU) count++;
                    q.push(v);
                }
            }
        }
        return count;
    }
};