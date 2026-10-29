class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>freq,pos;
            int k=0,matched=0;
            for(int j=i;j<n;j++){
                int v=nums[j];
                if(!pos.count(v))pos[v]=++k;
                int r=pos[v];
                if(freq[v]==r)matched--;
                freq[v]++;
                if(freq[v]==r)matched++;
                if(matched==k)ans++;
            }
        }
        return ans;
    }
};