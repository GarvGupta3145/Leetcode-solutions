class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(mx==nums[i])j=i;
            else if(nums[i]*2>mx)return -1;
        }
        return j;
    }
};