class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // As we go from left to right, do the stock prices go into the future?
        // How many shares of a stock can I hold at a time?
        // How long can I hold it for?
        // Is there a limit on how many times I can buy or sell the stock?

        // So I can buy and sell the stock, any number of time I want, and I want to increase the profit I earn.
        // so, if I have a list of stock prices, like [1, 3, 2, 4] then I cannot just buy on the running minimum (minimum stock price till now) and sell it on that day to see if I earn the maximum profit till now.
        // we could hold multiple stocks, multiple shares of a stock. I could have bought like three shares at one and then sold each one of them at 3, 2 and 4 and incurred the maximum profit.
        // but as we can only buy and sell it just once, what we can do is, we can try buying it on day one and selling it on the consecutive next day and adding it to the profit, we have already incurred till now because we can buy and sell any number of times. possible, but we cannot buy multiple shares of one stock.

        int revenue = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) { // This condition signifies if we can buy, if we can incur a profit by buying it the previous day and selling it on this day.
                revenue += (prices[i] - prices[i - 1]);
            }
        }

        return revenue;
    }
};