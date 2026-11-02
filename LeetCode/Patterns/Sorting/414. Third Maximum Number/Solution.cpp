class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int mx=nums[0];
        int smx=INT_MIN;
        int tmx=INT_MIN;
        if(nums.size()<3)return *max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mx){
                
                if(smx!=INT_MIN){
                    tmx=smx;
                    
                }
                smx=mx;
                mx=nums[i];
            }
            else if(nums[i]==mx)continue;
            else if(nums[i]<mx && nums[i]>smx){
                if(smx!=INT_MIN){
                    tmx=smx;
                    
                }
                smx=nums[i];
            }
            else if(nums[i]==smx)continue;
            else if(nums[i]>tmx && nums[i]<smx){
                tmx=nums[i];
            }
        }
        if(tmx!=INT_MIN)return tmx;
        return mx;
    }
};