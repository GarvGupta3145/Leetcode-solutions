class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>arr;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=2){
            int first=nums[i];
            int sec=nums[i+1];
            arr.push_back(sec);
            arr.push_back(first);
        }
        return arr;
    }
};