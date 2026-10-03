class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>freq(101,0);
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            mpp[nums[i]].push_back(i);
        }
        vector<int>ans(nums.size());
        int sum=0;
        
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0){
                for(auto ind:mpp[i]){
                    ans[ind]=sum;
                }
            }
            sum+=freq[i];
        }
        return ans;
    }
};