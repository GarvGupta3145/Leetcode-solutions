class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<unordered_set<int>> dp(n);
        dp[0].insert(grid[0][0]);
        for(int j=1;j<n;j++){
            for(int x:dp[j-1]) dp[j].insert(x^grid[0][j]);
        }
        for(int i=1;i<m;i++){
            unordered_set<int> cur;
            for(int x:dp[0]) cur.insert(x^grid[i][0]);
            dp[0]=move(cur);  // avoids an O(size) copy
            for(int j=1;j<n;j++){
                unordered_set<int> cur;
                for(int x:dp[j])   cur.insert(x^grid[i][j]);  
                for(int x:dp[j-1]) cur.insert(x^grid[i][j]);
                dp[j]=move(cur);  // avoids an O(size) copy
            }
        }
        int mn=INT_MAX;
        for(int x:dp[n-1]) mn=min(mn,x);
        return mn;
    }
};