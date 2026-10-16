class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int prev2=0;
        int prev1=nums[0];
        int m1=0;
        for(int i=1;i<nums.size()-1;i++){
            m1=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=m1;
        }
        int nprev2=0;
        int nprev1=nums[1];
        int m2=0;
        for(int i=2;i<n;i++){
            m2=max(nprev1,nprev2+nums[i]);
            nprev2=nprev1;
            nprev1=m2;
        }
        return max(m1,m2);
    }
};