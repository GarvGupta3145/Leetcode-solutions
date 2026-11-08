class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }

    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m + n);
        sz.assign(m + n, 1);
        for (int i = 0; i < m + n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    unite(i, m + j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && sz[find(i)] > 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};