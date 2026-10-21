class Solution {
public:
    int minOperations(string s) {
        if(s.size()==1)return 0;
        if(s.size()==2 && s[0]>s[1])return -1;
        bool sorted=true;
        for(int i=1;i<s.size();i++){
            if(s[i]<s[i-1])sorted=false;
        }
        if(sorted)return 0;

        char mx = *max_element(s.begin(), s.end());
        char mn = *min_element(s.begin(), s.end());
        int n = s.size();
        if(s[0]==mn || s[n-1]==mx) return 1;


        if(s[0]==mx && s[n-1]==mn && count(s.begin(), s.end(), mx)==1 && count(s.begin(), s.end(), mn)==1) return 3;

        return 2;

    }
};