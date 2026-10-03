class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2)return false;
        unordered_map<char,int>mpp;
        for(auto it:s1){
            mpp[it]++;
        }
        int unique=mpp.size();
        int l=0,r=0;
        int n=0;
        while(l<=r && r<n2){
            if(mpp.find(s2[r])==mpp.end()){
                while(l!=r){
                    mpp[s2[l]]++;
                    l++;
                }
                l++;
                r++;
                continue;
            }
            else{
                if(r-l+1==n1)return true;
                mpp[s2[r]]--;
                r++;

            } 
        }
        return false;
    }
};