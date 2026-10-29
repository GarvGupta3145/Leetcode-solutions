class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size(), ans=0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0) continue;
                if(i==0 || j==0) dp[i][j]=1;
                else dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
