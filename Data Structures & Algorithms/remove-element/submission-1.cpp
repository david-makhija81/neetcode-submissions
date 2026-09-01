class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // So, I must remove all the elements that are equal to val in the array nums.
        // What I may do is to make a new array go through every element in the input array, for each element if it is not equal to val I will put it into the array else I'll leave that element.
        // But, the removal must happen in-place only
        // So, it does not make any sense to declare a new array.
        // And, the only permitted operation in an array is to modify the value at a particular index.
        // Thus, what we can do is to mark the values that are equal to the given value and left shift the right part of the array ahead of it in order to replace it.

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == val) {
                nums[i] = -1;
            }
        }

        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != -1) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};