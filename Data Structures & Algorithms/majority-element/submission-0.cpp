class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // One straightforward approach is to count the occurrences of each element and return the one with the highest frequency, since the majority element appears more than ⌊n/2⌋ times.
        // But this would waste a lot of extra space. In the worst case, if we have a majority element occurring n/2 + 1 times and the rest of the elements are distinct integers, then we’ll be wasting O(n) space complexity.
        // One way I can think of is to sort the array. This will place all equal elements next to each other. Then I can keep a running count for the current element; if any element’s count exceeds ⌊n / 2⌋, I can return it. There will be only one such element.
        // But this would also require log n space complexity and n log n time complexity. Let’s see if I can think of any other approach.
        // Another note: what if, in the original array (not the sorted version), I could keep a running majority element?

        // I keep the count of the current element. If I encounter any other element, I decrement its frequency. If it is 0, I update the majority running element to that current element (where the frequency was made to be 0), and set the frequency to 1. I keep doing this: as the majority running element changes, the frequency drops down to 0, then I change the majority running element and reset the frequency to 1.

        // If any element is a majority element, then obviously its count would not fall to 0 at the end of the array. In the worst case, the majority element would be tugged towards the left part of the array, and if it occurs n/2 + 1 times, it will require n/2 + 1 more elements to cancel this frequency and change that majority element, which is not going to happen because the array only contains n elements (not n + 1 or n + 2), right. So that's the thing.

        int majElement = nums[0];
        int currFreq = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != majElement) {
                currFreq--;
            } else {
                currFreq++;
            }

            if(currFreq == 0) {
                majElement = nums[i];
                currFreq = 1;
            }
        }

        return majElement;
    }
};