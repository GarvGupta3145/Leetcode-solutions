class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<bitset<1024>> dp(n);
        dp[0][grid[0][0]]=1;
        for(int j=1;j<n;j++){
            for(int x=0;x<1024;x++)
                if(dp[j-1][x]) dp[j][x^grid[0][j]]=1;
        }
        for(int i=1;i<m;i++){
            bitset<1024> cur;
            for(int x=0;x<1024;x++)
                if(dp[0][x]) cur[x^grid[i][0]]=1;
            dp[0]=cur;
            for(int j=1;j<n;j++){
                bitset<1024> src=dp[j]|dp[j-1];   // merge top + left in one op
                bitset<1024> cur;
                for(int x=0;x<1024;x++)
                    if(src[x]) cur[x^grid[i][j]]=1;  // remap by XOR with the cell
                dp[j]=cur;
            }
        }
        return dp[n-1]._Find_first();  // lowest set bit = minimum value (GCC)
    }
};