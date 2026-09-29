class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> mn(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        mn[0][0] = 0;
        pq.push({0, 0, 0});
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            if (t > mn[i][j]) continue;
            if (i == n - 1 && j == m - 1) return t;

            int cost = 2;
            if ((i + j) % 2 == 0) cost = 1;

            for (int d = 0; d < 4; d++) {
                int x = i + dx[d];
                int y = j + dy[d];
                if (x < 0 || y < 0 || x >= n || y >= m) continue;

                int start = max(t, moveTime[x][y]);
                int nt = start + cost;
                if (nt < mn[x][y]) {
                    mn[x][y] = nt;
                    pq.push({nt, x, y});
                }
            }
        }
        return -1;
    }
};