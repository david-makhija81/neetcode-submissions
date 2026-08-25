class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // So, I am given a list of prices that are listed for each day and these are the prices are of a share on each day. I have to incur the maximum profit by buying and selling the share as many times as I like but I wait for at least cooldown number of days (which in this case is constant for every testcase and that is 1) before I buy the stock again
        // The straightforward approach to this problem would be to try buying selling the stock, and after selling it we wait for at least 1 day before buying it again.
        // We would try all the possible combinations of buying and selling with this approach and figure out the maximum profit.
        // But how do we do this?

        vector<int> sold(prices.size(), 0);
        vector<int> bought(prices.size(), 0);

        bought[0] -= prices[0];

        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            bought[i] -= prices[i];

            bought[i] = max(bought[i], bought[i - 1]);

            for(int j = 0; j < (i - 1); j++) {
                bought[i] = max(bought[i], sold[j] - prices[i]);
            }

            sold[i] = max(sold[i], sold[i - 1]);

            for(int j = 0; j < i; j++) {
                sold[i] = max(sold[i], bought[j] + prices[i]);
            }

            maxProfit = max(maxProfit, max(sold[i], bought[i]));
        }

        return maxProfit;
    }
};