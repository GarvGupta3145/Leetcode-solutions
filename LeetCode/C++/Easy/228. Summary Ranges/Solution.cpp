class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            int l=nums[i];
            int j=i+1;
            int a=l;
            while(j<nums.size() && nums[j]==a+1){
                a+=1;
                j++;
            }
            string s;
            s+=to_string(l);
            if(l<nums[j-1]){
                s+="->";
                s+=to_string(nums[j-1]);
            }
            ans.push_back(s);
            i=j-1;
        }
        return ans;
    }
};