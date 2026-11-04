class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }

        int mx = INT_MIN;
        int chunks = 0;

        for (int i = 0; i < arr.size(); i++) {
            mx = max(mx, arr[i]);

            freq[arr[i]]--;
            if (freq[arr[i]] == 0) {
                freq.erase(arr[i]);
            }

            if (freq.empty() || mx <= freq.begin()->first) {
                chunks++;
            }
        }

        return chunks;
    }
};