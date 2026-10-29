class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string s="1";
        for(int i=2;i<=n;i++){
            string rle="";
            int l=0;
            while(l<s.size()){
                char c=s[l];
                int count=1;
                l++;
                while(l<s.size() && s[l]==c){
                    count++;
                    l++;
                }
                rle+=to_string(count)+c;
            }
            s=rle;
        }
        return s;
    }
};