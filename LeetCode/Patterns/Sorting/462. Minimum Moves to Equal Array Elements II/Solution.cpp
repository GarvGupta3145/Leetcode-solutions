class Solution {
public:

// 1,2,5,5,8,13,13,14,18,22
// 10+9+6+6+3+2+2+3+7+11


    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=(nums[0]+nums[n-1])/2;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(mid-nums[i]);
        }
        return ans;

    }
};