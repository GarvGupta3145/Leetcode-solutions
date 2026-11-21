class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int>premx(n),suffmn(n);
        premx[0]=nums[0];suffmn[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            premx[i]=max(premx[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffmn[i]=min(suffmn[i+1],nums[i]);
        }
        int ind=-1;
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            int diff=suffmn[i+1]-premx[i];
            if(diff>=0 ){
                ans=diff;
                ind=i;
            }
        }
        return ind+1;
    }
};