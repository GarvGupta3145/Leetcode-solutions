class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = max(minIdx, maxIdx) + 1;
        int right = n - min(minIdx, maxIdx);
        int both = min(minIdx, maxIdx) + 1
                 + n - max(minIdx, maxIdx);

        return min({left, right, both});
    }
};