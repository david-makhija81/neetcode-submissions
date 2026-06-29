class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }

        vector<int> heistResult(nums.size(), 0);
        heistResult[0] = nums[0];
        heistResult[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++) {
            heistResult[i] = max(nums[i] + heistResult[i - 2], heistResult[i - 1]);
        }

        return heistResult[nums.size() - 1];
    }
};
