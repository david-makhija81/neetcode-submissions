class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if we had to merge the two erase into a third one, making a third one with a totally different address space, it would have been an easy problem, but this this, this, this proposal that we have to accommodate all the most elements into the nums one array only, kind of puts us off.
        // it would, if it was in, uh, it was putting, uh, it was about putting, the merged result of nums, one and nums, two, we would have just, uh, Made some pointers, uh, uh, we would have uh, compared the, uh, the 1st element of namsman with the 1st element of nams too, put it there, and this way, uh, we would have selected the minimum element of the, uh, of the remaining elements of namsman and nams to put it there, eliminated from the array we chose it from and then moved on.
        // but if we try to use that approach here, we might compromise the we might compromise the elements in the first array as we try to accommodate other array elements at the appropriate positions.
        // thus, instead of starting from the beginning of both the arrays, and trying to find the minimum of both and putting it in the, putting it at the back of the array, building the array from, from starting to the beginning to the ending, uh, we would try to build the merged array from ending to the beginning so that uh, because the uh, ending part of the 1st array is not yet occupied.
        // And if we did place any elements there, then obviously, if we did place any elements there, then. Then we would not be compromising any elements whatsoever because there are no elements there in the first place, so we can put any value up there.

        int posFin = m + n - 1;
        int ptr1 = m - 1, ptr2 = n - 1;

        while((ptr1 >= 0) && (ptr2 >= 0)) {
            if(nums1[ptr1] > nums2[ptr2]) {
                nums1[posFin] = nums1[ptr1];
                ptr1--;
                posFin--;
            } else {
                nums1[posFin] = nums2[ptr2];
                ptr2--;
                posFin--;
            }
        }

        while(ptr1 >= 0) {
            nums1[posFin] = nums1[ptr1];
            ptr1--;
            posFin--;
        }

        while(ptr2 >= 0) {
            nums1[posFin] = nums2[ptr2];
            ptr2--;
            posFin--;
        }
    }
};