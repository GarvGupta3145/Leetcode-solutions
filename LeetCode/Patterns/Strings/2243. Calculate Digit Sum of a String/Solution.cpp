class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int a=(int)s.size()/k;
            int m=(int)s.size()%k;
            int b=a;
            if(m!=0)b+=1;
            string temp;
            for(int i=0;i<b;i++){
                int sum=0;
                for(int j=0;j<k  && i*k+j<s.size();j++){
                    sum+=s[i*k+j]-'0';
                }
                temp+=to_string(sum);
            }
            s=temp;
        }
        return s;
    }
};