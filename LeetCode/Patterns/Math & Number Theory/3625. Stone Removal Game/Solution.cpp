class Solution {
public:
    bool canAliceWin(int n) {
        int st=10;
        bool win=true;
        while(st>0){
            if(n-=st>0)n-=st;
            else return !win;
            win=!win;
            st--;
        }
        return !win;
    }
};