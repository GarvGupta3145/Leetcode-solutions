class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int seq=1;
        int sum=nums[0];
        for(int i=0;i<nums.size();i++){
            int c=1;
            int total=nums[i];
            int j=i+1;
            while(j<nums.size() && nums[j]==nums[i]+1 ){
                c++;
                total+=nums[j];
                j++;
                i++;
            }
            i=j;
            if(seq==c)sum=max(sum,total);
            else if(c>sum)sum=total;
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