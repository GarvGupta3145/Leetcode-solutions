class Solution {
public:
    // Tabulation
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0]=grid[0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int best;
                int left,up;
                left= j==0?INT_MAX:dp[i][j-1];
                up=i==0?INT_MAX:dp[i-1][j];
                best=min(left,up);
                dp[i][j]=min
            }
        }
        return dp[m-1][n-1];
    }
};