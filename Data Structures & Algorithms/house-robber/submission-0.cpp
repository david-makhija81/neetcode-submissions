class Solution {
public:
    int rob(vector<int>& nums) {
        // So, I can not rob consecutive houses - is that what you are trying to say?
        // Is there a limit on how many houses I can rob?
        // And the amount I can rob from each house is different?
        // What's the minimum size of the array of houses?

        if(nums.size() == 1) {
            return nums[0]; // In this case there's only one house the robber can rob thus only one outcome.
        }

        // I suppose a greedy approach would not work here because a greeady approach would tell you to rob either the odd indexed houses or the even indexed houses.
        // And this approach kind of fails if we come across an array like [4,1,1,4] with greedy max possible robbery is 5 whereas it is clearly visible one can rob 8 without setting the alarm off.
        // I think a dynamic programming approach would fit best here,
        // While standing at a house the robber can either rob from the previous consecutive house or from this house - the amount that he gets if he does not steal from the previous house which is equal to amountStolenFrom(thisHouse) + amount stolen 2 houses back from here.
        // Thus, this way standing at each house he can maximize his profit till that house by making a choice between robbing this house or the previous house.

        vector<int> moneyRobbedTillThisHouse(nums.size(), 0);

        moneyRobbedTillThisHouse[0] = nums[0];

        moneyRobbedTillThisHouse[1] = max(moneyRobbedTillThisHouse[0], nums[1]);

        for(int i = 2; i < nums.size(); i++) {
            moneyRobbedTillThisHouse[i] = max(
                                            moneyRobbedTillThisHouse[i - 1],
                                            moneyRobbedTillThisHouse[i - 2] + nums[i]
                                        );
        }

        return moneyRobbedTillThisHouse[nums.size() - 1];
    }
};