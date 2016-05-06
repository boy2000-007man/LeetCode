class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        vector<int> first(prices.size(), 0);
        for (int i = 0, buy = INT_MAX; i < prices.size(); i++)
            first[i] = max(i ? first[i - 1] : 0, prices[i] - (buy = min(buy, prices[i])));
        for (int i = prices.size() - 1, second = 0, sell = INT_MIN; 0 <= i; i--)
            profit = max(profit, first[i] + (second = max(second, (sell = max(sell, prices[i])) - prices[i])));
        return profit;
    }
};