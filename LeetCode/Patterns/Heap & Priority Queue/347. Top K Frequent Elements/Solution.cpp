class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
        for(auto& [value,freq]:mpp){
            heap.push({freq,value});
            if(heap.size()>k)heap.pop();
        }
        vector<int>result(k);
        for(int i=k-1;i>=0;i--){
            result[i]=heap.top().second;
            heap.pop();
        }
        return result;
    }
};