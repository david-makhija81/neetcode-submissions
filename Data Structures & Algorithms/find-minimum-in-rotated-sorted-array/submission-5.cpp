class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        int result = nums[0];

        while(left <= right) {
            if(nums[left] < nums[right]) {
                result = min(nums[left], result);
            }

            int mid = ((right - left) / 2) + left;

            result = min(result, nums[mid]);

            if(nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};