class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int cost1 = prices[0], profit1 = 0;
    int cost2 = prices[0], profit2 = 0;
    for (int i = 1; i < prices.size(); i++) {
        cost1   = min(cost1, prices[i]);
        profit1 = max(profit1, prices[i] - cost1);
        cost2   = min(cost2, prices[i] - profit1);
        profit2 = max(profit2, prices[i] - cost2);
    }
    return profit2;
}
};