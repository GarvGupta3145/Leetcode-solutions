class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(), nums2.end());
        unordered_set<int> resultSet;
        
        for (int num : nums1) {
            if (binary_search(nums2.begin(), nums2.end(), num)) {
                resultSet.insert(num);
            }
        }
        
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};