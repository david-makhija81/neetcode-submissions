class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // So, we are given an array and we have to figure out the subarray that has maximum product out of all the subarrays.
        // Does the array contain 0s or negative integers?
        // If there were no negative elements or 0s we would have easily returned the entire array's product, but because of 0 & negative we have to be careful and ignore some times while having to include them other times.
        // If it was maximum sum subarray then we would have ignored the subarrays with negative sum altogether because they would steal the sum from the result anyways.
        // But because it is a product and if we find a negative product subarray then it might be of some use ahead as we might find another negative subarray with which this negative product cancels and it might give us a positive result.
        // To counter this, we must maintain the minimum negative and maximum positive product of all the subarrays up till a specific index for every index stored somewhere.
        // This way we can solve the subproblems incrementally, like if we know maximum product of a subarray until the index (idx - 1) and we ought to know the same result for the subarrays until index idx and the element on the current index is negative then it would produce the maximum by multiplying with the minimum negative element up to the previous index and it would produce the minimum by multiplying with the maximum positive these would come in use for further indexes in a similar way.

        vector<int> maxProduct(nums.size());
        vector<int> minProduct(nums.size());

        maxProduct[0] = nums[0];
        minProduct[0] = nums[0];

        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            maxProduct[i] = max(nums[i] * maxProduct[i - 1], nums[i] * minProduct[i - 1]);
            minProduct[i] = min(nums[i] * maxProduct[i - 1], nums[i] * minProduct[i - 1]);

            if(nums[i] > maxProduct[i]) {
                maxProduct[i] = nums[i];
            }
            if(nums[i] < minProduct[i]) {
                minProduct[i] = nums[i];
            }

            ans = max(maxProduct[i], ans);
        }

        return ans;
    }
};