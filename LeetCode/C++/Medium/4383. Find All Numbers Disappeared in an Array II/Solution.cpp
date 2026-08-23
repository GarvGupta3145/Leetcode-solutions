class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        int cur = lower - 1;

        while (i < n && nums[i] < lower) {
            i++;
        }

        for (; i < n && nums[i] <= upper; i++) {
            if (cur >= nums[i]) continue;
            else if (cur + 1 == nums[i]) {
                cur = nums[i];
                continue;
            } else {
                ans.push_back({cur + 1, nums[i] - 1});
                cur = nums[i];
            }
        }
        if (cur + 1 <= upper) ans.push_back({cur + 1, upper});
        return ans;
    }
};