class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            l=l^nums[i];
        }
        if(l==0)return n-1;
        return n;
    }
};