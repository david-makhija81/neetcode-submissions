class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Are the numbers sorted in any fashion or arranged randomly?
        // Does the array contain any negative or zero numbers?

        // A simple solution could be to select a number (could be randomly) from the array and then try pairing it up with another number from the array such that the pair's sum equals the target, if the pair's sum fails to meet the target then we try pairing it up with another number from the array.
        // So, in this case the algorithm looks something like go through the array maybe from left to right pick each and every element try pairing this element with another element which we search in the entire array.
        // But this algorithm requires about O(n^2) number of operations.
        // Alternatively, we could sort the array this pushes the least element to left of the array and the biggest number to the right of the array.
        // After we can maybe choose a pair which has average value of all the possible pairs, and maybe compare it with target if falls short of target we replace the smallest value of pair with a bigger and similarly if the pair sum shoots off the value of target we replace the bigger element with a smaller one until we are unable to do so.
        // One easy way to do this is to sort the array, keep 2 pointers one at the leftMost corner and the other at the rightMost corner - the pair of these 2 values in a sorted array the least and highest value assumes roughly an average value of all the possible pairs.
        // Afterwards, we push the left pointer to the right (thus replacing the least value with a bigger one) - if the sum falls short of target, and pushing the right pointer to the left if the sum overshoots the target.

        int leftIdx = 0, rightIdx = nums.size() - 1;

        vector<int> numsDuplicate = nums;

        sort(nums.begin(), nums.end());

        while(leftIdx < rightIdx) { // while 2 do not collide
            if((nums[leftIdx] + nums[rightIdx]) == target) {
                break; // We have found the pair, thus no more searching
            }

            if((nums[leftIdx] + nums[rightIdx]) > target) {
                rightIdx--;
            } else {
                leftIdx++;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(numsDuplicate[i] == nums[leftIdx]) {
                leftIdx = i;
                break;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if((numsDuplicate[i] == nums[rightIdx]) && (i != leftIdx)) {
                rightIdx = i;
                break;
            }
        }

        return {min(leftIdx, rightIdx), max(rightIdx, leftIdx)};
    }
};