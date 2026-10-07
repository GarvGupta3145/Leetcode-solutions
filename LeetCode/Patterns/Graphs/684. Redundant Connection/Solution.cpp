class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        parent[pu] = pv;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSet ds(n);

        for (auto edge : edges) {
            if (!ds.unionSet(edge[0], edge[1]))
                return edge;
        }

        return {};
    }
};