class Solution {
    vector<int> p;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    // endpoint k (0 or 1) of the slash in cell (r, c), as point (x, y)
    pair<int, int> ends(char ch, int r, int c, int k) {
        if (ch == '/') return k == 0 ? make_pair(c + 1, r) : make_pair(c, r + 1);
        return k == 0 ? make_pair(c, r) : make_pair(c + 1, r + 1);
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int B = n * n;  // one extra node for the whole boundary
        p.resize(n * n + 1);
        iota(p.begin(), p.end(), 0);

        int dr[4] = {-1, -1, 0, -1};
        int dc[4] = {0, -1, -1, 1};

        int count = 1;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                char ch = grid[r][c];
                if (ch == ' ') continue;

                vector<int> roots[2];
                for (int k = 0; k < 2; k++) {
                    auto e = ends(ch, r, c, k);
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr < 0 || nc < 0 || nc >= n) continue;
                        char nch = grid[nr][nc];
                        if (nch == ' ') continue;
                        for (int j = 0; j < 2; j++) {
                            if (ends(nch, nr, nc, j) == e) {
                                roots[k].push_back(find(nr * n + nc));
                            }
                        }
                    }
                    if (e.first == 0 || e.first == n || e.second == 0 || e.second == n) {
                        roots[k].push_back(find(B));
                    }
                }

                bool loop = false;
                for (int a : roots[0])
                    for (int b : roots[1])
                        if (a == b) loop = true;
                if (loop) count++;

                int me = r * n + c;
                for (int k = 0; k < 2; k++)
                    for (int x : roots[k]) p[find(x)] = find(me);
            }
        }
        return count;
    }
};