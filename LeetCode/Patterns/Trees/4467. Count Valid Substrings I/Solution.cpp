class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        int last = -1;

        for (int j = 0; j < n; j++) {
            if (j >= 2 && s[j - 2] == 'a' && s[j - 1] == 'b' && s[j] == 'c') {
                last = j - 2;
            }
            ans += j - last;
        }

        return ans;
    }
};