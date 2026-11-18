class Solution {
public:
    int maxProduct(int n) {
        int a=0;
        int b=0;
        int c=n;
        while(c){
            int d=c%10;
            if(d>=a){
                b=a;
                a=d;
            }
            else if(d>b)b=d;
            c/=10;
        }
        return a*b;
    }
};