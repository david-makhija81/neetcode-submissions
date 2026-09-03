class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // we can consider Subarray as a window of contiguous elements inside the original array.
        // we have to return the minimum possible size of such window, such that this total entire sum of that window is greater than or equal to target.
        // Are the elements positive only, or can they be negative as well?
        // as all the elements are positive, if I add an element into an existing window, the sum, the total sum of that array is obviously going to increase by some amount.
        // thus, one solution could be that I keep adding elements to the window until the entire sum of the window is greater than or equal to the target.
        // so now I have a window that is, that has a sum greater than or equal to the target, but I want the minimum length of this window. So now what I do is I start eliminating elements from this window until the sum stays greater than or equal to target.
        // and I stop at the point where it is just at, at the brink of going below the, where the sum is just at the brink of going below, the target, and that is our minimum length of the current window, we do this until we have, um, explored all, like, until we have tried eliminating and window with all the elements in the array.
        // And at the end of it, we have our minimum length.

        int left = 0, right = 0;
        int minLength = nums.size() + 1;
        int sum = 0;

        while(right < nums.size()) {
            sum += nums[right];
            right++;

            while((sum - nums[left]) >= target) {
                sum -= nums[left];
                left++;
            }

            if(sum >= target) {
                minLength = min(minLength, (right - left));
            }
        }

        return (minLength == (nums.size() + 1)) ? 0 : minLength;
    }
};