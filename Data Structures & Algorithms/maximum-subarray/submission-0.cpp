class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, leftEnd = 0, result = 0;

        for(int rightEnd = 0; rightEnd < nums.size(); rightEnd++) {
            sum += nums[rightEnd];

            while(sum < 0) {
                sum -= nums[leftEnd++];
            }

            result = max(sum, result);
        }

        int maxElement = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            maxElement = max(nums[i], maxElement);
        }

        if(maxElement < 0) {
            return maxElement;
        }

        return result;
    }
};