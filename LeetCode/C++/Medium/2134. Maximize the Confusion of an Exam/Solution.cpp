class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t=0,f=0;
        int ct=0,cf=0;
        int mnt=0,mnf=0;
        int l=0,r=0;
        while(l<=r && r<answerKey.size()){
            if(answerKey[r]=='T'){
                t++;
            }
            else{
                if(ct<k)ct++;
                else{
                    while(l<r && answerKey[l]!='F'){
                        l++;
                        t--;
                    }
                    l++;
                }
            }
            mnt=max(mnt,r-l+1);
            r++;
        }
        l=0,r=0;
        while(l<=r && r<answerKey.size()){
            if(answerKey[r]=='F'){
                f++;
            }
            else{
                if(cf<k)cf++;
                else{
                    while(l<r && answerKey[l]!='T'){
                        l++;
                        f--;
                    }
                    l++;
                }
            }
            mnf=max(mnf,r-l+1);
            r++;
        }
        return max(mnf,mnt);
    }
};