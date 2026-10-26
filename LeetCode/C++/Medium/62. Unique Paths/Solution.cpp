class Solution {
public:
    // int solve(int r,int c,vector<vector<int>>& dp){
    //     if(r==0 && c==0){
    //         return 1;
    //     }
    //     if(r<0 || c<0) return 0;
        
    //     if(dp[r][c] != -1) return dp[r][c];
    //     return dp[r][c]=solve(r,c-1,dp) + solve(r-1,c,dp);
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return solve(m-1,n-1,dp);
    // }

    // Tabulation 
    int uniquePaths(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int p1=j-1>=0?dp[i][j-1]:0;
                int p2=i-1>=0?dp[i-1][j]:0;
                dp[i][j]=p1+p2;
            }
        }
        return dp[m-1][n-1];
    }
};