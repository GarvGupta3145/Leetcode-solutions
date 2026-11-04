class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int,int>mpp;
        vector<int>nums=arr;
        sort(nums.begin(),nums.end());
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        int ans=0;
        int curr=nums[0];
        int mc=arr[0];
        int l=0;
        for(int i=0;i<arr.size();i++){
            mc=max(mc,arr[i]);
            mpp[arr[i]]--;
            while(l<nums.size() && nums[l]<=mc && mpp[nums[l]]==0)l++;
            if(l<nums.size() && nums[l]>=mc)ans++;

        }
        return ++ans;
    }
};