class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(4));
    dp[0] = {prices[0], 0, prices[0], 0};
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i-1][0], prices[i]);               // cost after 1st buy
        dp[i][1] = min(dp[i-1][1], dp[i-1][0] - prices[i]);  // net cost after 1st sell
        dp[i][2] = min(dp[i-1][2], dp[i-1][1] + prices[i]);  // net cost after 2nd buy
        dp[i][3] = min(dp[i-1][3], dp[i-1][2] - prices[i]);  // net cost after 2nd sell
    }
    return -dp[n-1][3];
}
};