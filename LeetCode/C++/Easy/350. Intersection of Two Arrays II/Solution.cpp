class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);

        unordered_map<int, int> freq;
        for (int x : nums1) freq[x]++;

        vector<int> res;
        for (int x : nums2) {
            auto it = freq.find(x);
            if (it != freq.end() && it->second > 0) {
                res.push_back(x);
                it->second--;
            }
        }
        return res;
    }
};