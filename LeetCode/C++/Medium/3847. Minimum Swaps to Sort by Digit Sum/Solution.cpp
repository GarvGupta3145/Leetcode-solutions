class Solution {
public:
    int minSwaps(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<pair<int,pair<int,int>>>temp;
        for(int i=0;i<nums.size();i++){
            int cpy=nums[i];
            int digit=0;
            while(cpy){
                 digit+=(cpy%10);
                 cpy/=10;
            }
            mp[nums[i]]=i;
            temp.push_back({digit,{nums[i],i}});
        }
     sort(temp.begin(),temp.end());
     int count=0;
      for(int correct=0;correct<temp.size();correct++){
        int target=temp[correct].second.first;
        if(nums[correct]!=target){
            count++;
            int current=mp[target];
            int displaced=nums[correct];
            swap(nums[correct],nums[current]);
            mp[target]=correct;
            mp[displaced]=current;
        }
      }
     return count;
    }
};