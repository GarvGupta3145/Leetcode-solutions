class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        if (n == 1) return 0;

        vector<int> L(n), R(n);

        // left-to-right: earliest valid index for each skill[i]
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && station[p] != skill[i]) p++;
            L[i] = p;
            p++;
        }

        // right-to-left: latest valid index for each skill[i]
        int q = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (q >= 0 && station[q] != skill[i]) q--;
            R[i] = q;
            q--;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, R[i + 1] - L[i]);
        }
        return ans;
    }
};