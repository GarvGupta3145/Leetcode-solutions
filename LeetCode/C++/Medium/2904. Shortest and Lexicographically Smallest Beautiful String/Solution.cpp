class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0,r=0;
        int nm=INT_MAX;
        int count=0;
        string st;

        while(l<=r && r <s.size()){
            while(l<s.size() && s[l]!='1'){
                if(l==r){
                    r++;
                }
                l++;
            }
            if(s[r]=='1'){
                count++;
                if(count==k){
                    if(nm=r-l+1){
                        st=s.substr(l,r-l+1);
                        nm=r-l+1;
                    }
                    count-=1;
                    l++;
                    while(l<s.size() && s[l]!='1'){
                        if(l==r){
                            r++;
                        }
                        l++;
                    }
                }
            }
            r++;
        }
        return st;
    }
};