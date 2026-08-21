class Solution {
public:
    int search(vector<int>& nums, int target) {
        // The is sorted so let's try to use it to our advantage.
        // Let's keep a search range, as the array is sorted the median (middle element) of this array can give us a great deal of insight into where exactly is the target lying in this search range.
        // For example, if the target is lesser than the median then the target must lie in the left half of the array else if the target is greater then it lies in right half.
        // Else if the median is equal to the target then we return it's index.

        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int mid = ((right - left) / 2) + left;

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};