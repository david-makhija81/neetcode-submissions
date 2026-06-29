class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxInThisWindow(prices.size(), 0);

        maxInThisWindow[prices.size() - 1] = prices[prices.size() - 1];

        for(int i = prices.size() - 2; i >= 0; i--) {
            maxInThisWindow[i] = max(prices[i], maxInThisWindow[i + 1]);
        }

        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++) {
            maxProfit = max(maxProfit, (maxInThisWindow[i] - prices[i]));
        }

        return maxProfit;
    }
};
