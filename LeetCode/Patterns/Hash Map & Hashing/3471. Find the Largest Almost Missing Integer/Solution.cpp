class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n)return -1;
        // Case: k=1 or k=n -> every position has window-count 1
        if (k == 1) {
            unordered_map<int,int> freq;
            for (int x : nums) freq[x]++;
            int ans = -1;
            for (auto& [val, cnt] : freq)
                if (cnt == 1) ans = max(ans, val);
            return ans;
        }
        if(k==n){
            return *max_element(nums.begin(), nums.end());
        }

        // Case: 1 < k < n -> only first/last can qualify
        int cnt0 = 0, cntN = 0;
        for (int x : nums) {
            if (x == nums[0]) cnt0++;
            if (x == nums[n - 1]) cntN++;
        }

        int ans = -1;
        if (cnt0 == 1) ans = max(ans, nums[0]);
        if (cntN == 1) ans = max(ans, nums[n - 1]);
        return ans;
    }
};