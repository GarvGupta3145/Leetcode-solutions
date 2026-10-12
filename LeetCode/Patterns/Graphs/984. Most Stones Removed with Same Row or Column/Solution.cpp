class DSU {
public:
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu(20002);
        unordered_set<int> used;

        for (auto& s : stones) {
            int r = s[0], c = s[1] + 10001;
            dsu.unite(r, c);
            used.insert(r);
            used.insert(c);
        }

        int groups = 0;
        for (int x : used)
            if (dsu.find(x) == x) groups++;

        return stones.size() - groups;
    }
};