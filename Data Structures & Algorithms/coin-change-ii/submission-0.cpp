class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // We have to return the number of ways we can sum up to the given amount with given denominations of coins. 
        // The straightforward approach would be to try all the combinations that sum up to the given amount and return the total number of ways from there.
        // But this approach would take about exponential number of operations, thus we have to look for an approach that does the approach in lesser time.
        // There must be a less complex which requires lesser number of operations.
        // Another approach that might work here, is to start from smaller subproblems where the size of the array taken into consideration is lesser and the amount upto which we are calculating the result is also smaller.
        // This way we keep calculating the successive results until we have considered all the elements in the array and we have tried to sum them up to the target amount.

        vector<vector<unsigned long long>> numberOfWays(coins.size(), vector<unsigned long long>(amount + 1, 0));

        for(int i = 0; i <= amount; i += coins[0]) {
            numberOfWays[0][i] = 1;
        }

        for(int i = 1; i < coins.size(); i++) {
            for(int j = 0; j <= amount; j++) {
                numberOfWays[i][j] += numberOfWays[i - 1][j];

                if((j - coins[i]) >= 0) {
                    numberOfWays[i][j] += numberOfWays[i][j - coins[i]];
                }
            }
        }

        return numberOfWays[coins.size() - 1][amount];
    }
};