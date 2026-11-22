class Solution {
public:
    bool checkString(string s) {
        int b=0;
        for(int i=0;i<s.size();i++){

            if(s[i]=='b' && b==0)b++;
            else if( s[i]=='a' && b==1)return false;
        }
        return true;
    }
};