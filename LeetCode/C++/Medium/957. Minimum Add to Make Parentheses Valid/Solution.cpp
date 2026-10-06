class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        int ans=0;
        for(auto ch:s){
            if(ch=='(')open++;
            else close++;
            if(close>open){
                ans++;
                close--;
            }
        }
        if(open>close)ans+=open-close;
        return ans;
    }
};