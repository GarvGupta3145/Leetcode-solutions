class Solution {
public:
    int minChanges(string s) {
        int one=0;
        int a=0;
        int ans=0;
        for(int i=0;i<s.size()-1;i+=2){
            if(s[i]!=s[i+1])ans++;
        }
        return ans;
    }
};