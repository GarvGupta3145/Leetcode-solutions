class Solution {
    vector<int> p;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = n + 1;
        p.resize(m * m);
        iota(p.begin(), p.end(), 0);

        // every point on the outer border is one connected piece
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n || j == n) {
                    p[find(i * m + j)] = find(0);
                }
            }
        }

        int count = 1;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == ' ') continue;

                int a, b;
                if (grid[r][c] == '/') {
                    a = r * m + (c + 1);
                    b = (r + 1) * m + c;
                } else {
                    a = r * m + c;
                    b = (r + 1) * m + (c + 1);
                }

                int pa = find(a), pb = find(b);
                if (pa == pb) count++;
                else p[pa] = pb;
            }
        }
        return count;
    }
};