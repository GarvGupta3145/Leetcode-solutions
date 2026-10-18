class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int del=0;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int j=i+1;
            while(j<nums.size() && nums[j]==a){
                del++;
                j++;
            }
            i=j-1;
        }
        return del;
    }
};