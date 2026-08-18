class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // The array we are is randomly arranged, right? No sorting?
        // We have look for an integer sequence out of the array in which all of the integers are consecutive in increasing order right?
        // The elements in the sequence vs the elements in the array need not be in the same order, right?

        if(nums.size() == 0) {
            return 0;
        }

        // Let's take an example, if we have an array [5, 3, 2, 1] then the answer for this is [1, 2, 3] thus 3 is the length of this sequence and 3 is our answer, alright.
        // If we sort the array in an ascending order all the consecutive elements are pushed together.
        // Thus, after sorting we can maintain a window of consecutive keep filling the window with the next element we find only if the next element is consecutive in value to the last integer of the window.
        // We reset the window if the next is not consecutive in value to the last element of the window, and because the sequence can no longer continue from here on.
        // Thus, we reset the window to start from here and repeat this process until we have searched the entire array.

        int windowLeft = 0, windowRight = 1; // the window Only has one element
        int maxSequenceLength = 1;

        sort(nums.begin(), nums.end());

        vector<int> numsWithoutDuplicates;

        for(int i = 0; i < nums.size(); i++) {
            if(numsWithoutDuplicates.empty() || (numsWithoutDuplicates.back() != nums[i])) {
                numsWithoutDuplicates.push_back(nums[i]);
            }
        }

        while(windowRight < numsWithoutDuplicates.size()) {
            if(numsWithoutDuplicates[windowRight] != (numsWithoutDuplicates[windowRight - 1] + 1)) {
                windowLeft = windowRight;
            }

            windowRight++;

            maxSequenceLength = max(maxSequenceLength, (windowRight - windowLeft));
        }

        return maxSequenceLength;
    }
};