class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while(num!=0){
            if(num>=1000){
                int l=num/1000;
                for(int i=0;i<l;i++)ans+="M";
                num%=1000;
            }
            else if(num>=100){
                int l=num/100;
                if(l==9)ans+="CM";
                else if(l>=5){
                    ans+="D";
                    for(int i=0;i<l-5;i++)ans+="C";
                }
                else if(l==4)ans+="CD";
                else for(int i=0;i<l;i++)ans+="C";
                num%=100;
            }
            else if(num>=10){
                int l=num/10;
                if(l==9)ans+="XC";
                else if(l>=5){
                    ans+="L";
                    for(int i=0;i<l-5;i++)ans+="X";
                }
                else if(l==4)ans+="XL";
                else for(int i=0;i<l;i++)ans+="X";
                num%=10;
            }
            else{
                int l=num;
                if(l==9)ans+="IX";
                else if(l>=5){
                    ans+="V";
                    for(int i=0;i<l-5;i++)ans+="I";
                }
                else if(l==4)ans+="IV";
                else for(int i=0;i<l;i++)ans+="I";
                num=0;
            }
        }
        return ans;
    }
};