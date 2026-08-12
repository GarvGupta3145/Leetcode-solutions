class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        int mx=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]<k){
                mp[nums[i]]++;
                count++;
            }
            else if(mp[nums[i]]==k){
                while(l<=i && nums[l]!=nums[i]){
                    mp[nums]--;
                    count--;
                    l++;
                }
                l++;
            }
            mx=max(mx,count);
        }
        return mx;
    }
};