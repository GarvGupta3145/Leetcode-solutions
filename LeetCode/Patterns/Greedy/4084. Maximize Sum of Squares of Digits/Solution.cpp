class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s="";
        if(num*9<sum)return "";
        while(num){
            if(sum-9>=0){
                s+='9';
                sum-=9;
                num--;
            }
            else if(sum<9 && sum >0){
                s.push_back('0'+sum);
                sum=0;
                num--;
            }
            else{
                s+='0';
                num--;
            }
        }
        return s;
    }
};