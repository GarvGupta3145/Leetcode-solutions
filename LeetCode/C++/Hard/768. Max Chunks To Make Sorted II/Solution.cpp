class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int,int>mpp;
        vecot
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        int ans=0;
        int mx=*max_element(arr.begin(),arr.end());
        int mn=*min_element(arr.begin(),arr.end());
        int curr=mn;
        int mc=arr[0];
        for(int i=0;i<arr.size();i++){
            mc=max(mc,arr[i]);
            mpp[arr[i]]--;
            
            if(curr>=mc)ans++;

        }
        return ans;
    }
};