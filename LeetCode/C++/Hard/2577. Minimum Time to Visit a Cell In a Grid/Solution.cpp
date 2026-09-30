class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();
            if (t > dist[r][c]) continue;
            if (r == m - 1 && c == n - 1) return t;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                int nt = t + 1;
                if (grid[nr][nc] > nt) {
                    nt = grid[nr][nc] + (grid[nr][nc] - nt) % 2;
                }
                if (nt < dist[nr][nc]) {
                    dist[nr][nc] = nt;
                    pq.push({nt, nr, nc});
                }
            }
        }
        return -1;
    }
};