class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        bool a=true;;
        for(int i=0;i<nums.size();i++){
            l=l^nums[i];
            if(nums[i]!=0)a=true;
        }
        if(l!=0)return n;
        if(l==0 && a==true)return n-1;
        return 0;
    }
};