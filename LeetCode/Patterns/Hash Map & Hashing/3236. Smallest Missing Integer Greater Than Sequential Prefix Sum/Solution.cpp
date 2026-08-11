class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            while(j<nums.size() && nums[j]==nums[i]+1){
                sum+=nums[j];
                j++;
                i++;
            }
            break;
        }
        int mmin=sum;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        while(true){
            if(mpp.find(mmin)!=mpp.end())mmin++;
            else break;
        }
        return mmin;

    }
};