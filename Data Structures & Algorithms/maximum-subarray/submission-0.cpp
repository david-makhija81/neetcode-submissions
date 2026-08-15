class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Does the array contain negative integers?
        // If it does contain negative integers can the maximum sum be negative?

        // If all the Elements in the array were non-negative then the sum of the entire array would have been the answer.
        // But because there are negative elements, thus we maintain a subarray - keep adding elements into it and updating its sum.
        // If at any point the subarray sum becomes negative then the subarray we have been progressing with would only decrease the overall sum of the subarrays to come thus we drop the subarray that we had been progressing with and start adding elements from next index.

        int maxSum = nums[0];
        int sum = 0;

        for(int num: nums) {
            sum += num;
            maxSum = max(sum, maxSum);

            if(sum < 0) {  // The subarray that we carried till here will only decrease the subarray that follows.
                sum = 0;  // Thus we start fresh and start a subarray from the next element.
            }
        }

        return maxSum;
    }
};