class Solution {
public:
    bool isPalindromic(string s) {
        string bin;
        for(char c:s){
            int x=c;;
            for(int i=7;i>=0;i--){
                bin+=((x>>i)&1)+'0';
            }
        }
        int i=0,j=bin.size()-1;
        while(i<j){
            if(bin[i]!=bin[j])return false;
            i++;
            j--;
        }
        return true;
    }
};