class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(k, {INT_MAX, 0}));
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                int buy = i ? dp[i-1][j].first : INT_MAX;
                int sell = i ? dp[i-1][j].second : 0;
                if(j==0) dp[i][j].first=min(buy,prices[i]);
                else dp[i][j].first=min(buy,prices[i]-dp[i][j-1].second);
                dp[i][j].second=max(sell,prices[i]-dp[i][j].first);
            }
        }
        return dp[n-1][k-1].second;
    }
};