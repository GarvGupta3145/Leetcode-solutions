class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size(), ans=0;
        vector<vector<pair<int,int>>> dp(m, vector<pair<int,int>>(n));  // (row run, col run)
        vector<vector<int>> sz(m, vector<int>(n,0));                    // squares ending at this cell
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0){ dp[i][j]={0,0}; continue; }
                dp[i][j].first  = (j>0 ? dp[i][j-1].first  : 0) + 1;
                dp[i][j].second = (i>0 ? dp[i-1][j].second : 0) + 1;
                int diag = (i>0 && j>0) ? sz[i-1][j-1] : 0;
                sz[i][j] = min({diag+1, dp[i][j].first, dp[i][j].second});
                ans += sz[i][j];
            }
        }
        return ans;
    }
};