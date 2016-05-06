class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,
            buy = INT_MAX;
        for (int price: prices)
            profit = max(profit, price - (buy = min(buy, price)));
        return profit;
    }
};