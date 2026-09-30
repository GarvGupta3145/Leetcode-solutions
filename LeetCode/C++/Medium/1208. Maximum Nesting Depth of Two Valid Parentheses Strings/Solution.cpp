class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int open=0;
        int n=seq.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                open++;
                if(open%2!=0)ans[i]=0;
                else ans[i]=1;
            }
            else{
                if(open%2!=0)ans[i]=0;
                else ans[i]=1;
                open--;
            }
        }
        return ans;
    }
};