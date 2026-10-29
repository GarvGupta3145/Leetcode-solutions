class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size(), ans=0;
        vector<int>dp(n,0);
        dp[0]=a[0][0];
        ans+=dp[0];
        int prev=ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }
                int old=dp[j];
                if(a[i][j]==0){
                    dp[j]=0;
                    prev=old;
                    continue;
                }
                if(i==0 || j==0){
                    if(a[i][j]==1){
                        ans+=1;
                        dp[j]=1;
                        prev=old;
                    }
                    continue;
                }
                int best;
                best=1+min(dp[j-1],min(dp[j],prev));
                ans+=best;
                dp[j]=best;
                prev=old;
            }
        }
        return ans;
    }
};
