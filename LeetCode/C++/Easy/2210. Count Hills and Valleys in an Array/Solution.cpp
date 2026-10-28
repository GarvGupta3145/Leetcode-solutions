class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            int j=i+1;
            while(j<nums.size() && nums[j]==nums[i])j++;
            if(j==n)break;
            else{
                int next=nums[j];
                if(prev>nums[i] && next>nums[i]){
                    count++;
                }
                else if(prev<nums[i] && next < nums[i]){
                    count++;
                }
            }

            prev=nums[i];
            i=j-1;
        }
        return count;
    }
};