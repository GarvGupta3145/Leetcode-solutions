class Solution {
public:
    void wiggleSort(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int n=nums.size();
         vector<int>ans;
         int l=(n/2)-1,h=n-1;
         if(n%2!=0) l=n/2;
         while(l>=0 && h>l){
            ans.push_back(nums[l]);
            ans.push_back(nums[h]);
            l--;
            h--;
         }
         for(int i=0;i<ans.size();i++){
            nums[i]=ans[i];
         }

    }
};