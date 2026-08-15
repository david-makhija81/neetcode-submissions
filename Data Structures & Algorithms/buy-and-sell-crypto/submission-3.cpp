class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Is there a minimum period I have to hold on stock for?
        // Is there a limit on how many times I can buy or sell the stock?
        // If I encounter an array like [3, 2, 1] where I cannot make any profit no matter when I buy or sell it - what do I return then?

        // To attain the maximum profit one can buy at the lowest price and sell at the highest price.
        // But this logic fails here for example if the global minimum occurs after the global maximum like in the array [2, 3, 1] here I cannot buy on the third day sell it on the second day because time is unidirectional.
        // Thus we must maintain a runningMinimum to solve this problem.

        int runningMinimum = prices[0]; // We keep updating it as we go through all the prices.

        int maxProfit = 0; // We keep updating this as well and return it at the end.

        for(int price: prices) {
            runningMinimum = min(price, runningMinimum);

            int profit = price - runningMinimum; // The profit if I buy it at the minimum encountered till now and sell it on the current price.

            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};