class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i=0;
        int j=0;
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3)return false;
        for(int k=0;k<s3.size();k++){
            if(i<n1 && j<n2){
                if(s1[i]==s3[k] && s2[j]!=s3[k])i++;
                else if(s1[i]!=s3[k] && s2[j]==s3[k])j++;
                else{
                    int l=i+1,r=j+1;
                    int m=k+1;

                    while(l<n1 && r<n2 && m<n3 ){
                        if(s1[l]==s3[m] && s2[r]==s3[m]){
                            l++,r++;
                            m++;
                            continue;
                        }
                        else if(s1[l]==s3[m]){
                            k=m;
                            i=l+1;
                            break;
                        }
                        else {
                            k=m;
                            j=r+1;
                            break;
                        }
                    }
                }
                
            }
            else if(i==n1){
                while(j<n2){
                    if(s3[k]==s2[j])k++,j++;
                    else return false;
                }
            }
            else if(j==n2){
                while(i<n1){
                    if(s3[k]==s1[i])i++,k++;
                    else return false;
                }
            }
        }
        return true;
    }
};