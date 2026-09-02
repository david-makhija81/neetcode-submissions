class Solution {

    void mergeSort(vector<int>& nums, int startPoint, int endPoint) {

        if((startPoint >= endPoint) || ((startPoint + 1) == endPoint)) {
            return;
        }

        mergeSort(nums, startPoint, (((endPoint - startPoint) / 2) + startPoint));
        mergeSort(nums, (((endPoint - startPoint) / 2) + startPoint), endPoint);

        vector<int> firstHalf;

        for(int i = startPoint; i < (((endPoint - startPoint) / 2) + startPoint); i++) {
            firstHalf.push_back(nums[i]);

        }

        vector<int> secondHalf;

        for(int i = (((endPoint - startPoint) / 2) + startPoint); i < endPoint; i++) {
            secondHalf.push_back(nums[i]);
        }

        int firstPtr = 0;
        int secondPtr = 0;

        for(int i = startPoint; i < endPoint; i++) {
            if(firstPtr == firstHalf.size()) {
                nums[i] = secondHalf[secondPtr];
                secondPtr++;
            } else if(secondPtr == secondHalf.size()) {
                nums[i] = firstHalf[firstPtr];
                firstPtr++;
            } else {
                if(firstHalf[firstPtr] < secondHalf[secondPtr]) {
                    nums[i] = firstHalf[firstPtr];
                    firstPtr++;
                } else {
                    nums[i] = secondHalf[secondPtr];
                    secondPtr++;
                }
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        // So I have to sort the array. Sorting the array means putting all the elements in a given order—either ascending or descending—and in our case, it's ascending (i.e., non-decreasing).
        // in the sorted array, every element must have a position. No matter how randomly you pick up the elements, in the sorted version of that sequence, every element must have a signified position.
        // let's try to find that exact position for each and every element
        // there is one more quality to the sorted version of the array that every neighboring element to the left must be lesser than the neighboring element at the immediate right of it.
        // there's one approach I can think of is that I pick an element and I keep swapping it with its immediate right neighbor. I keep doing this until that element reaches its exact position where it belongs. That is lesser than the next right immediate value.
        // this approach is also known as bubble sort. Here, as we are moving a bigger element until the next immediate element is greater than or equal to this element. This is bubble sort as it pushes the greater elements to the right of the array, and the smaller elements are ultimately pushed to the left of the array as we keep swapping this bigger element with the smaller elements that come its way.
        // but this algorithm might take us like n square time complexity, which we can make it lesser, I suppose
        // alternatively, the other thing I can think of is taking two arrays, assuming it is sorted, and then merging them. Merging it in a way that the resultant array of the two merged arrays is also sorted. That way, if we start atomically from arrays of one sizes and we make our way to the array of N size, we can automatically get a sorted array in N log N time complexity, and I suppose log N space complexity

        int n = nums.size();

        mergeSort(nums, 0, n);

        return nums;
    }
};