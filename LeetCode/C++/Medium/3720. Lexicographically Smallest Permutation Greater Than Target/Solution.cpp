class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        for (int i = 0; i < n; i++) {

            // Try to keep the same character as target[i]
            if (freq[target[i] - 'a'] > 0) {
                ans += target[i];
                freq[target[i] - 'a']--;
            }
            else {
                // Find the smallest character greater than target[i]
                int j = target[i] - 'a' + 1;

                while (j < 26 && freq[j] == 0)
                    j++;

                // No greater character -> need to backtrack
                if (j == 26) {
                    while (!ans.empty()) {
                        int last = ans.back() - 'a';
                        ans.pop_back();
                        freq[last]++;

                        int k = target[ans.size()] - 'a' + 1;

                        while (k < 26 && freq[k] == 0)
                            k++;

                        if (k < 26) {
                            ans += char('a' + k);
                            freq[k]--;

                            // Fill remaining with smallest characters
                            for (int x = 0; x < 26; x++) {
                                while (freq[x] > 0) {
                                    ans += char('a' + x);
                                    freq[x]--;
                                }
                            }

                            return ans;
                        }
                    }

                    return "";
                }

                // We can make the answer greater here
                ans += char('a' + j);
                freq[j]--;

                // Fill remaining characters in sorted order
                for (int x = 0; x < 26; x++) {
                    while (freq[x] > 0) {
                        ans += char('a' + x);
                        freq[x]--;
                    }
                }

                return ans;
            }
        }

        // s itself is equal to target
        // Need the next greater permutation
        while (!ans.empty()) {
            int last = ans.back() - 'a';
            ans.pop_back();
            freq[last]++;

            int k = target[ans.size()] - 'a' + 1;

            while (k < 26 && freq[k] == 0)
                k++;

            if (k < 26) {
                ans += char('a' + k);
                freq[k]--;

                for (int x = 0; x < 26; x++) {
                    while (freq[x] > 0) {
                        ans += char('a' + x);
                        freq[x]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};