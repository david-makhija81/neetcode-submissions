class Solution {
public:
    int climbStairs(int n) {
        // If n = 0 then the person has to just stay ther itself to reach the n = 0 step thus only one way to reach there.
        // If n = 1 then the answer is 1, I can take only one step to reach their no other permutations/combinations.
        if(n <= 1) {
            return 1;
        }
        // If n = 2 then he can either go in steps [1,1] or he can just take 2 steps in one go and reach the n = 2 step
        // If n = 3 then I have to look to at the number of ways I can reach at the steps (n - 2) and (n - 1) because these are the only 2 positions from where the n = 3 step is accessible.
        // I will thus add up the number of ways it requires to reach (n - 2) & the number of ways it requires to reach (n - 1).
        // This way I can start from the 0th stair keep on calculating the number of ways to get to the successive stairs until I reach the nth stair

        vector<int> numberOfWaysToReachThisStair(n + 1, 0); // Initially there's no way to get to any of the stairs.

        numberOfWaysToReachThisStair[0] = 1;
        numberOfWaysToReachThisStair[1] = 1;

        for(int i = 2; i <= n; i++) {
            numberOfWaysToReachThisStair[i] =
                            numberOfWaysToReachThisStair[i - 1] +
                            numberOfWaysToReachThisStair[i - 2];
        }

        return numberOfWaysToReachThisStair[n];
    }
};