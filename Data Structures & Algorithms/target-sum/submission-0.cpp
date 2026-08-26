class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // So, I have an array nums and considering all the elements in an arithmetic operation a number from the array can either be subtracted from the expression or it can be added to it.
        // We have to make various expressions this way and there must be a result associated with that expression - that result must be equal to target, we have to count such expressions.
        // Let's look at a test case for this problem, we have target as 4 and we have [2, 1, 1] so there is only one way one can reach the target by forming an expression from these numbers and that is +2+1+1 and now we change that test case provided earlier and the new array becomes [2, 1, 1, 2] and the target becomes 6.
        // In the new test case we just added a new element into the previous array and we must know all the expressions from previous array and the results from those expressions and there are only two possibilities that this new element can be adjusted into the already calculated expressions and that is either adding into the previous expressions or subtracting from them.
        // And this way we can easily divide a problem into subproblems and keep building until the last step.

        int entireSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<long long>> numberOfWays(nums.size(), vector<long long>(((2 * max(entireSum, abs(target))) + 1), 0));

        int offset = max(entireSum, abs(target));

        numberOfWays[0][offset - nums[0]] = 1;
        numberOfWays[0][offset + nums[0]] = 1;

        if(nums[0] == 0) {
            numberOfWays[0][offset - nums[0]] = 2;
        }

        for(int i = 1; i < nums.size(); i++) {
            for(int j = ((-1) * max(entireSum, abs(target))); j <= max(entireSum, abs(target)); j++) {
                if((offset + j - nums[i]) >= 0) {
                    numberOfWays[i][offset + j] += numberOfWays[i - 1][offset + j - nums[i]];
                }
                if((offset + j + nums[i]) <= (2 * max(entireSum, abs(target)))) {
                    numberOfWays[i][offset + j] += numberOfWays[i - 1][offset + j + nums[i]];
                }

                // cout << "Index: " << i << ", Amount: " << j << ", Ways: " << numberOfWays[i][offset + j] << endl;
            }
        }

        return numberOfWays[nums.size() - 1][offset + target];
    }
};