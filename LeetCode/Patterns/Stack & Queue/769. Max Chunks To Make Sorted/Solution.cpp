class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        long long sum=0;
        bool found0=false;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)found0=true;
            sum+=arr[i];
            if(i*(i+1)/2==sum && found0==true)ans++;
        }
        return ans;
    }
};