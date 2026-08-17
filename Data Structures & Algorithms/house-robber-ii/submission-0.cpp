class Solution {
public:
    int rob(vector<int>& nums) {
        // So, we can not rob from last house if we rob from the first house?

        // So, it is clear to me that if I rob from the ith house I have to then only go to the (i + 2)th house and ahead.
        // I think the robber must make a plan standing at each house he must evaluate gains he can make if he robs this house vs if he leaves this house in order to be able to rob the previous one.
        // If there's a list he maintains going through all the houses writing down max profit he can make till that house, then at every house he must compare the gain from this house + the gain from 2 houses behind this one vs the gain till the previous house.
        // But we have another condition as well, where we can not rob from the last house if we robbed the first house, thus we'll consider 2 case - 1 where we only consider the 1st house and leave aside the last house and the second one where we keep aside the first house and consider the last house.
        // After calculating the max gain in both the situations - we return the maximum out of both of them.

        if(nums.size() == 1) {
            return nums[0]; // This is the only house we can rob.
        }

        if(nums.size() == 2) {
            return max(nums[0], nums[1]); // We can only rob one out of the 2.
        }

        vector<int> maxGainsIn1stCase(nums.size(), 0); // If we do not consider the last house.
        maxGainsIn1stCase[0] = nums[0];
        maxGainsIn1stCase[1] = max(nums[0], nums[1]);
        for(int i = 2; i < (nums.size() - 1); i++) {
            maxGainsIn1stCase[i] = max(
                maxGainsIn1stCase[i - 1],
                maxGainsIn1stCase[i - 2] + nums[i]
            );
        }

        vector<int> maxGainsIn2ndCase(nums.size(), 0); // If we do not consider the 1st house.
        maxGainsIn2ndCase[1] = nums[1];
        maxGainsIn2ndCase[2] = max(nums[1], nums[2]);
        for(int i = 3; i < nums.size(); i++) {
            maxGainsIn2ndCase[i] = max(
                maxGainsIn2ndCase[i - 1],
                maxGainsIn2ndCase[i - 2] + nums[i]
            );
        }

        return max(
            maxGainsIn1stCase[nums.size() - 2], 
            maxGainsIn2ndCase[nums.size() - 1]
        );
    }
};