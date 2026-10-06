class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        while(true)
            int a =n;
            int sum=0;
            while(a){
                int d=a%10;
                sum+=(d*d);
                a/=10;
            }
            if(sum==1)return true;
            if(s.count(sum))return false;
            else{
                s.insert(sum);
                n=sum;
            }
        }
        return false;
    }
};