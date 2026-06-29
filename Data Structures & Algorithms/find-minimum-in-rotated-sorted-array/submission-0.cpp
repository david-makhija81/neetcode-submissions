class Solution {
public:
    int findMin(vector<int> &nums) {
        int rotateCount = nums.size();

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] > nums[i]) {
                rotateCount = i;
                break;
            }
        }

        return nums[rotateCount % (nums.size())];
    }
};
