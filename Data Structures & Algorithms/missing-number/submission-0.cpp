class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Are the numbers all positive or do they contain any negative integers?
        // What's the limit of n?

        int n = nums.size();

        // So, if I have a sum of all the elements from 0 through n - then this sum apparently has been contributed by each and every element from through n.
        // But, if we summed the total of the array that we have been provided with the that lacks one contribution out of the n + 1 elements ranging from 0 through n.
        // Thus, we can calculate this missing contribution by subtracting the sum of the array from the total sum of n + 1 elements.
        // For example, if we have a sequence like [n, n - 1, ..., m, ... 1, 0] where all of these are consecutive elements from 0 through n and m is the missing element in the array, so the array would look something like [n, n - 1, ..., m + 1, m - 1, ..., 1, 0] - in this case of we subtracted the array from the sequence it is apparent that every other element would get cancelled out and we'll only be left with m itself

        long long sumOfSequence = 0;

        for(int i = 0; i <= n; i++) {
            sumOfSequence += i;
        }

        long long sumOfArray = 0;

        for(int num: nums) {
            sumOfArray += num;
        }

        int missingNumber = sumOfSequence - sumOfArray;

        return missingNumber;
    }
};