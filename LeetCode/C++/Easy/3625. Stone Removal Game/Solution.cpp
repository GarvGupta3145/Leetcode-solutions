class Solution {
public:
    bool canAliceWin(int n) {
        n-=10;
        int sum=0;
        bool a=false;
        if(n<0)return false;
        if(n<9)return true;
        for(int i=n-1;i>=0;i--){
            sum+=i;
            if(sum==0 &&a==false)return false;
            else if(sum==0 && a==true)return false;
            if(a)a=false;
            else a=true;
        }
        return !a;
    }
};