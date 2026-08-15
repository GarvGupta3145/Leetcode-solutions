class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int a=0;;
        for(int i=0;i<nums.size();i++){
            l=l^nums[i];
            if(nums[i]==0)a++;
        }
        if(a==n)return 0;
        if(l==0)return n-1;
        return n;
    }
}; 