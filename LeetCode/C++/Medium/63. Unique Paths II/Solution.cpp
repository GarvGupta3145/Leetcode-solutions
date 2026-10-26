class Solution {
public:

    // Memoization
    // int solve(vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp,int i,int j){
    //     if(i<0 || j<0)return 0;
    //     if(obstacleGrid[i][j]==1)return dp[i][j]=0;
    //     if(i==0 && j==0)return 1;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     else return dp[i][j]=solve(obstacleGrid,dp,i,j-1)+solve(obstacleGrid,dp,i-1,j);
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
    //     return solve(obstacleGrid,dp,obstacleGrid.size()-1,obstacleGrid[0].size()-1);
    // }

    //Tabulation
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    //     vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
    //     dp[0][0]=1;
    //     int m=obstacleGrid.size();
    //     int n=obstacleGrid[0].size();
    //     if(obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1)return 0;
    //     for(int i=0;i<obstacleGrid.size();i++){
    //         for(int j=0;j<obstacleGrid[0].size();j++){
    //             if(i==0 && j==0)continue;
    //             if(obstacleGrid[i][j]==1){
    //                 continue;
    //             }
    //             int left=j-1>=0?dp[i][j-1]:0;
    //             int upper=i-1>=0?dp[i-1][j]:0;
    //             dp[i][j]=left+upper;
    //         }
    //     }
    //     return (m-1>=0 && n-1>=0)?dp[m-1][n-1]:0;
    // }

    //Space Optimization(2 Array)
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    //     int m=obstacleGrid.size();
    //     int n=obstacleGrid[0].size();
    //     vector<int>upper(n,0);
    //     if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
    //     if(m==1 && n==1 && obstacleGrid[0][0]==0)return 1;
    //     for(int i=0;i<m;i++){
    //         vector<int>same(n,0);
    //         for(int j=0;j<n;j++){
    //             if(i==0 && j==0)continue;
    //             if(obstacleGrid[i][j]==1)continue;
    //             int left=0,up=0;
    //             if(i==0 && j-1==0)left=1;
    //             else if(j-1>=0)left=same[j-1];

    //             if(i==1 && j==0)up=1;
    //             else if(i-1>=0)up=upper[j];

    //             same[j]=left+up;
    //         }
    //         upper=same;
    //     }
    //     return (m-1>=0 && n-1>=0)?upper[n-1]:0;
    // }
     
    //Space Optimization(1 Array)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;

        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1) dp[i]=0;
            if(i>0 && dp[i-1]==0) dp[i]=0;
        }

        for(int r=1;r<m;r++){
            for(int c=0;c<n;c++){
                if(r==0 && c==0 ) continue;
                if(obstacleGrid[r][c] == 1){
                    dp[c]=0;
                    continue;
                }
                // dp[c] = dp[c]+dp[c-1];
                if(c>0) dp[c] = dp[c]+dp[c-1];
            }
        }
        return dp[n-1];
    }
};