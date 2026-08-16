class Solution {
public:
    int findMin(vector<int>& nums) {
        // If n equals the number of elements in the array and the array gets rotated n times then does it come back it's previous order only?


        // The minimum element of a sorted array is the left most element of that array.
        // But now that the sorted array is further rotated, we know that the left most element has been pushed further rightwards in to the array.
        // If I rotate an array say m times where m < n (the number of elements in the array) then a chunk of m number of elements are taken out from the end of the array and are put in front of the array.
        // Thus, in an array like this - the first m elements are all greater than the next (n - m) elements.
        // And the first m elements are sorted separately and the other (n - m) are sorted among themselves.
        // Thus, if we go through the elements of this array one by one towards right - the elements keep on increasing until the mth element (the number of rotations) the value of (m + 1)th element drops drastically and then it starts increasing again.
        // And here the (m + 1)th character was once the left most character of a sorted array thus it is the minimum element of the array.
        // Thereby, to spot the minimum element in an array like this we can just go through the array checking where the right element is lesser than the left element.
        // The above approach takes linear time, we can look at an approach that is logarithmic as well.
        // We may use binary search to find the pivot (the index to which the array has been rotated).
        // We define a search space and keep dividing that range in half until we get to our goal.
        // We start with the entire array as our search space.
        // We keep an element which stores the minimum element encountered in the entire array.
        // We compare the middle element of our search space with the left most element.
        // If the left most element is greater than or equal to the middle element then the middle element is in the right portion - thus we need shrink the search space towards the right, 
        // And if the middle element is lesser than the left most element than the middle element is in right portion thus the answer is left to the middle element and thus we shrink the search space.

        int left = 0, right = (nums.size() - 1);
        int ans = nums[0];

        while(left <= right) {
            if(nums[left] < nums[right]) {
                ans = min(ans, nums[left]);
                break;
            }

            int mid = (((right - left) / 2) + left);

            ans = min(ans, nums[mid]);

            if(nums[left] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};