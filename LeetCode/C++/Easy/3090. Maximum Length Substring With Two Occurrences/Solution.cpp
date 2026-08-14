class Solution {
public:
    int maximumLengthSubstring(string s) {
        if(s.size()==0) return 0;
        int n=s.size();
        int left=0;
        int right=0;
        int Max=1;
        unordered_map<char,int>mpp;
        while(left<n && right<n){
            char c=s[right];
            mpp[c]++;
            if(mpp[c]>2){
                while(s[left]!=c){
                    mpp[s[left]]--;
                    left++;
                }
                mpp[s[left]]--;
                left++;
            }
            
            Max=max(Max,right-left+1);
            right++;
        }
        return Max;

    }
};