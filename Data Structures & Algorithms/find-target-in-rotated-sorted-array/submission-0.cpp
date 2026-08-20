class Solution {

    int binarySearch(int target, vector<int>& nums, int left, int right) {
        while(left <= right) {
            int mid = left + ((right - left) / 2);

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

    int findPivot(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int minimumElement = nums[0];
        int pivotIdx = 0;

        while(left <= right) {
            if(nums[left] <= nums[right]) {
                if(minimumElement > nums[left]) {
                    minimumElement = nums[left];
                    pivotIdx = left;
                }
                break;
            }

            int mid = left + ((right - left) / 2);

            if(minimumElement > nums[mid]) {
                minimumElement = nums[mid];
                pivotIdx = mid;
            }

            if(nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return pivotIdx;
    }

public:
    int search(vector<int>& nums, int target) {
        // Are there duplicates in the array?

        // So, you're saying that the array was sorted earlier and then it was rotated say m times
        // So, if the array was [0, 1, 2, 3, 4, 5] and m is 3 then the array that we receive is [3, 4, 5, 0, 1, 2].
        // So, inherently we are just partitioning the array in 2 parts first part ranges from 0th index to (n - m - 1)th index and the other part from (n - m)th index to (n - 1)th index, and then they just swapped them.
        // So, it is apparent that the array that we get has 2 parts - the first part was earlier the right part of an array sorted in ascending order and the second was earlier the left part of the same array.
        // Thus, it is apparent that both the parts of the array must be sorted and every element in first part is greater than every element in the second part.
        // Thus, if the target that we have to find is greater than equal to the leftmost element of the first part (nums[0]) then the target is to be found in first part and otherwise in the second part
        // And because both the parts are sorted, one can easily find a target in them via binary search.
        // Now, the only thing that we need is a way to figure out where exactly the first part ends and the second one starts.
        // We could try finding the minimum element in the array via binary search we start with the entire search space, if the leftmost element of the search space is greater than the righmost element then the left most is in the first part of the array and rightmost part is in the second part of the array and the smallest element is in this range only. If the middle element is lesser than the leftmost element of the search space then the middle element is in the second part of the array thus the minimum element is to the left of it thus we shrink the search space in that direction only and vice-versa in the other case.

        if(nums[0] <= nums[nums.size() - 1]) {
            return binarySearch(target, nums, 0, nums.size() - 1);
        }

        int pivotIdx = findPivot(nums);
        // cout << pivotIdx;

        if(target >= nums[0]) {
            return binarySearch(target, nums, 0, pivotIdx - 1);
        }

        return binarySearch(target, nums, pivotIdx, nums.size() - 1);
    }
};