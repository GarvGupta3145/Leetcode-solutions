class Solution {
public:
    int solve(vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp,int i,int j){
        if(i<0 || j<0)return 0;
        if(obstacleGrid[i][j]==1)return dp[i][j]=0;
        if(i==0 && j==0)return 1;
        
        else return dp[i][j]=solve(obstacleGrid,dp,i,j-1)+solve(obstacleGrid,dp,i-1,j);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        return solve(obstacleGrid,dp,obstacleGrid.size()-1,obstacleGrid[0].size()-1);
    }
};