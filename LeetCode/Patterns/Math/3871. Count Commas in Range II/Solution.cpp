class Solution {
public:

    // (10^6-10^3)*1+(10^9-10^6)*2+(n-10^6)
    
    // 528,580,435,893
    // count=12
    // 999,999=999,999-1,000
    long long countCommas(long long n) {
        int count=0;
        long long d=n;
        while(d!=0){
            d=d/10;
            count++;
        }
        if(count<4)return 0;
        int i=3;
        int j=1;
        long long ans=0;
        while(i<count){
            if(count-i>3){
                //1,112,112 c=7
                ans+=(pow(10,i+3)-pow(10,i))*j+1;
                j++;
                i+=3;
                //j=2,i=6
             }
             else{
                ans=ans+((n-pow(10,i))*j);
                break;
             }
        }
        //999,000
        return ans+1;
    }
};