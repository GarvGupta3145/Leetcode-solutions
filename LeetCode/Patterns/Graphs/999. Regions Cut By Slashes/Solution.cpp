class DSU {
    vector<int> parent;

public:
    DSU(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) parent[pa] = pb;
    }
};

class Solution {
    // neighbors already processed: top, top-left, left, top-right
    int dr[4] = {-1, -1, 0, -1};
    int dc[4] = {0, -1, -1, 1};

    // endpoint k (0 or 1) of the slash in cell (r, c), as point (x, y)
    pair<int, int> ends(char ch, int r, int c, int k) {
        if (ch == '/') return k == 0 ? make_pair(c + 1, r) : make_pair(c, r + 1);
        return k == 0 ? make_pair(c, r) : make_pair(c + 1, r + 1);
    }

    // groups touching the point e, among the already-processed neighbors
    // of cell (r, c), plus the boundary group if e lies on the border
    vector<int> collect(pair<int, int> e, int r, int c, vector<string>& grid, DSU& dsu) {
        int n = grid.size();
        int B = n * n;
        vector<int> groups;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nc < 0 || nc >= n) continue;
            char nch = grid[nr][nc];
            if (nch == ' ') continue;
            for (int j = 0; j < 2; j++) {
                if (ends(nch, nr, nc, j) == e) {
                    groups.push_back(dsu.find(nr * n + nc));
                }
            }
        }
        if (e.first == 0 || e.first == n || e.second == 0 || e.second == n) {
            groups.push_back(dsu.find(B));
        }
        return groups;
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(n * n + 1);  // n*n cells + 1 node for the whole boundary

        int count = 1;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                char ch = grid[r][c];
                if (ch == ' ') continue;
                int me = r * n + c;

                vector<int> g1 = collect(ends(ch, r, c, 0), r, c, grid, dsu);
                vector<int> g2 = collect(ends(ch, r, c, 1), r, c, grid, dsu);

                // both ends lead to the same group -> a loop closes
                bool loop = false;
                for (int a : g1)
                    for (int b : g2)
                        if (a == b) loop = true;
                if (loop) count++;

                for (int g : g1) dsu.unite(g, me);
                for (int g : g2) dsu.unite(g, me);
            }
        }
        return count;
    }
};