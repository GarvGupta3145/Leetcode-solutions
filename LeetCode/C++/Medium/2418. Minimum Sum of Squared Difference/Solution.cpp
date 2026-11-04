class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<nums1.size();i++){
            int diff=abs(nums1[i]-nums2[i]);
            if(diff>0)pq.push({diff,i});
        }
        while((k1 || k2)&& !pq.empty()){
            auto [diff,i]=pq.top();
            pq.pop();
            
            if(k1){
                if(nums1[i]>nums2[i]){
                    nums1[i]--;
                }
                else nums1[i]++;
                k1--;
            }
            else if(k2){
                if(nums1[i]>nums2[i]){
                    nums2[i]++;;
                }
                else nums2[i]--;
                k2--;
            }
            pq.push({diff-1,i});
        }
        long long ans=0;
        for(int i=0;i<nums1.size();i++){
            ans+=(nums1[i]-nums2[i])*(nums1[i]-nums2[i]);
        }
        return ans;
    }
};