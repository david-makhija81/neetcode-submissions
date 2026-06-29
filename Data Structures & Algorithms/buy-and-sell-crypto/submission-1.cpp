class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyDay = 0, profit = 0, sellDay = 0;
        while (sellDay < prices.size()) {
            while (prices[sellDay] < prices[buyDay]) {
                buyDay++;
            }
            profit = max(profit, prices[sellDay] - prices[buyDay]);

            sellDay++;
        } 
        return profit;
    }
};
