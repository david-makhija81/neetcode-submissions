class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // So, I am given a set of coins and from this set of coins I have to make a combination of these coins in such a way that it needs the fewest number of coins.
        // Maybe, if we chose the maximum denomination coins then it might help us choose the minimum number of coins.
        // Let's try it out with an example - denominations = [1, 3, 4, 5], amount = 7
        // With the approach we just discussed we might at first choose 5 which is the maximum denomination and so the remaining amount up to which we need to sum the coins is 2.
        // To sum up to 2 we can not choose 3 or 4 or 5, thus the only option left for us is to choose 2 one denomination coins - and that makes the result 3 coins whereas this amount could be achieved with just 2 coins i.e. one 3 denomination coin and one 4 denomination coin.
        // Thus, we can not move forward with the above approach.
        // On another note, if I have to sum up to a value let's say 10, and the coins we have with us are [1, 2] then I can sum up to 10 if and only if I can sum up to 8 or 9 because I can only use either the 1 denomination or the 2 denomination.
        // This way, I believe I can break down the question into steps where the number of steps are all the numbers from 1 all the way up to the amount and for each number I figure the minimum of coins needed to sum up to the number given the denominations of coins. We repeat this until we reach the target amount.

        vector<long long> minCoins(amount + 1, LLONG_MAX);

        minCoins[0] = 0;

        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(((i - coins[j]) >= 0) && (minCoins[i - coins[j]] < LLONG_MAX)) {
                    minCoins[i] = min(minCoins[i], minCoins[i - coins[j]] + 1);
                }
            }
        }

        return minCoins[amount];
    }
};