class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0;
        int p=1;
        int num=n;
        while(num){
            int d=num%10;
            s+=d;
            p*=d;
            num/=10;
        }
        if(n%(s+p)==0)return true;
        return false;
    }
};