class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> seen(1001, false);
        for (int x : nums1) seen[x] = true;

        vector<int> res;
        for (int x : nums2) {
            if (seen[x]) {
                res.push_back(x);
                seen[x] = false; // so it's added only once
            }
        }
        return res;
    }
};