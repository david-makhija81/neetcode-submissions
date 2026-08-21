class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // The straightforward approach would be to select 1 element to be the first integer of the pair and then try every other element if it sums up to target with the first element.
        // The above approach is kind of costly and requires order of (n^2) operations.
        // The array is sorted right? What if we could take advantage of that?
        // It makes sense to start with a pair with average value of all the possible pairs formed from the array, and increase the sum of the pair by replacing the minimum element with a bigger element if the pair sum is lesser than the target and decrease the sum of the pair by replacing the maximum element by smaller element if the pair sum is greater than target.
        // Thus, to make the above happen we keep 2 pointers - 1 pointing at the leftMost element in the beginning and the other one pointing at the rightMost element in the array - because this pair assumes roughly the average of all pairs and if we want increase the pair sum we just move the left pointer further to the right and if the sum is greater than target we move the right pointer further to the left.

        int left = 0, right = numbers.size() - 1;

        while(left < right) {
            if((numbers[left] + numbers[right]) == target) {
                break;
            }

            if((numbers[left] + numbers[right]) > target) {
                right--;
            } else {
                left++;
            }
        }

        return {left + 1, right + 1};
    }
};