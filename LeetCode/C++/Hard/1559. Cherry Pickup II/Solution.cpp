class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prev(n, vector<int>(n, -1));
        vector<vector<int>> curr(n, vector<int>(n, -1));

        prev[0][n - 1] = grid[0][0] + (n == 1 ? 0 : grid[0][n - 1]);

        int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        for (int i = 1; i < m; i++) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int j2 = j1; j2 < n; j2++) {
                    int best = -1;
                    for (int d = 0; d < 9; d++) {
                        int a = j1 + dx[d], b = j2 + dy[d];
                        if (a < 0 || a >= n || b < 0 || b >= n) continue;
                        if (a > b) swap(a, b);
                        best = max(best, prev[a][b]);
                    }
                    if (best == -1) curr[j1][j2] = -1;
                    else curr[j1][j2] = best + grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                }
            }
            swap(prev, curr);
        }

        int ans = 0;
        for (int j1 = 0; j1 < n; j1++)
            for (int j2 = j1; j2 < n; j2++)
                ans = max(ans, prev[j1][j2]);
        return ans;
    }
};