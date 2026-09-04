class Solution {

    bool canSplit(vector<int>& nums, int target, int k) {
        // how do we ensure that maximum sum of a subair can be equal to a less than target or not?
        // what should we check, by the way, should we check if any subberies some can exceed target or not?
        // simply put, if. If Target is the largest sum of a Sabare, if the erase partitioned into cases are erase, then no Sabare would exceed the target element. No Sabre would exceed the no Subarray sum would exceed the target element, and even after not exceeding the target sum, they would be able to be partitioned into K or lesser number of subarrays.
        
        int currSum = 0, cnt = 1;

        for(int i = 0; i < nums.size(); i++) {
            if((currSum + nums[i]) > target) {
                cnt++;
                if(cnt > k) {
                    return false;
                }
                currSum = nums[i];
            } else {
                currSum += nums[i];
            }
        }

        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        // Are the elements sorted in any order?
        // so we have to divide the elements of the array nums, we have to divide these elements into K subarrays.
        // let's say, a subarray denotes a bucket.
        // I have to make K buckets. And in each bucket, I must put any number of contiguous elements.
        // on another note, what are the two extremes in which, in between which, the value of the largest sum, if it is divided into K suber is the largest sum of a suberre, what is the range in which it lies, that largest sum?
        // one case could be that K equals to one, and in that case, the whole array is our answer, because we have to assign each an element to some sub array, and because there is only one sub array, every element gets assigned to that, array, and does the maximum answer for that could be, could be I'm not saying it is, it could be, um, the total sum of the array.
        // and one another case could be that K is equal to the length of nums, and in that case, um, the, I would have to partition the subarrays into, length one arrays, that is the only answer in that case, and uh, that is the only solution in that case, and the maximum element would be the maximum sum of such subarray.
        // now that we have a range in which the maximum sum, the largest sum of such a subway, if you split the are in K-parts, we have a range, what is the range, minimum value, tends towards the maximum element, as we talked earlier, and the maximum value of such sum is equal to The whole sum of the numbers array.
        // now that we have arrange, we can maybe apply binary research, we, we have arrange, we pick up mid element, after that, we have a mid element, we check, if this mid element, can denote the largest sum of the subberi. Sorry, largest sum of all these are areas if it is split into K.

        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int minLargestSum = right;

        while(left <= right) {
            int mid = ((right - left) / 2) + left;

            if(canSplit(nums, mid, k)) {
                minLargestSum = min(minLargestSum, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minLargestSum;
    }
};