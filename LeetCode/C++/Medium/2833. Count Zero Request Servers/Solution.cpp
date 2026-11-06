class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<pair<int, int>> qs;
        for (int i = 0; i < q; i++) {
            qs.push_back({queries[i], i});
        }
        sort(qs.begin(), qs.end());

        vector<int> cnt(n + 1, 0), ans(q);
        int active = 0, l = 0, r = 0, m = logs.size();

        for (auto& [t, idx] : qs) {
            while (r < m && logs[r][1] <= t) {
                if (cnt[logs[r][0]]++ == 0) {
                    active++;
                }
                r++;
            }
            while (l < m && logs[l][1] < t - x) {
                if (--cnt[logs[l][0]] == 0) {
                    active--;
                }
                l++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};