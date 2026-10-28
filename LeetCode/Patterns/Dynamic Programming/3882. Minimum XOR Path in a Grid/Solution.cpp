class Solution {
public:
    // Tabulation
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int curr=grid[i][j];
                    int best=grid[i][j];
                    int left=0,up=0;
                    left= j==0?0:dp[i][j-1];
                    up=i==0?0:dp[i-1][j];
                    best=min(best^left,best^up);
                    dp[i][j]=best;
            }
        }
        return dp[m-1][n-1];
    }
};