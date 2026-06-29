class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> HouseStart1(nums.size(), 0);
        vector<int> HouseStart2(nums.size(), 0);

        HouseStart1[0] = nums[0];
        HouseStart1[1] = max(nums[0], nums[1]);

        for(int i = 2; i < (nums.size() - 1); i++) {
            HouseStart1[i] = max(HouseStart1[i - 1], HouseStart1[i - 2] + nums[i]);
        }

        HouseStart2[1] = nums[1];
        HouseStart2[2] = max(nums[1], nums[2]);

        for(int i = 3; i < nums.size(); i++) {
            HouseStart2[i] = max(HouseStart2[i - 1], HouseStart2[i - 2] + nums[i]);
        }

        return max(HouseStart1[nums.size() - 2], HouseStart2[nums.size() - 1]);
    }
};