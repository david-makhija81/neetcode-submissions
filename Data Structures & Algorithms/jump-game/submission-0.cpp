class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currPos = nums.size() - 1;

        while(currPos > 0) {
            int nextStep = currPos - 1;
            while((nextStep >= 0) and (nums[nextStep] < (currPos - nextStep))) {
                nextStep--;
            }

            if(nextStep == -1) {
                return false;
            }

            currPos = nextStep;
        }

        return true;
    }
};