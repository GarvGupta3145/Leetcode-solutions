class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long ans = 0;

        // largest start index i such that some subsequence "a", "ab", "abc"
        // starting at or after i ends at or before the current position
        int a = -1, ab = -1, abc = -1;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'c') {
                abc = max(abc, ab);
            } else if (s[j] == 'b') {
                ab = max(ab, a);
            } else {
                a = j;
            }
            ans += j - abc;
        }

        return ans;
    }
};