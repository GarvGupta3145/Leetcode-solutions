class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a,b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        int i=2;
        int n=nums.size();
        while(i<n){
            if(a.back()>b.back())a.push_back(nums[i]);
            else b.push_back(nums[i]);
            i++;       
        }
        i=0;
        while(i<b.size()){
            a.push_back(b[i]);
            i++;
        }
        return a;
    }
};