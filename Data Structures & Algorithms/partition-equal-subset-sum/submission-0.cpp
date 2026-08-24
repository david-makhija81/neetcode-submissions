class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // So, we have to make 2 subsets such that the sum of elements of both the subsets is equal.
        // So, we may just make one subset of the array whose sum is equal to half of entire array's sum and the elements we did not include in this subset then would make another subset which sums up to the difference between the entire array's sum and the sum of the subset we chose earlier. That means both arrays' sums are equal.
        // Thus, we just have to look for a subset of elements that sums up to the half of entire array's sum.
        // The straightforward approach would be to make all possible subsets with target Sum equal to half of the sum of the whole array, if even one such subset exists we return true.
        // But this would take a lot of time/ a lot of operations.
        // Another approach that might work here is to solve this problem step by step where in each step I would mark the values that the subset pulled out from elements of the array of this size can sum up to.
        // And these values would help me in successive steps to mark values that the subsets pulled out from an array of this size can sum up to.
        // And at the end we return true if a subset can assume the value of half the sum of nums array.

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if((sum % 2) != 0) {
            return false;
        }

        vector<vector<bool>> valuePossible(nums.size(), vector<bool>((sum / 2) + 1, false));

        valuePossible[0][0] = true;

        if(nums[0] <= (sum / 2)) {
            valuePossible[0][nums[0]] = true;
        } 

        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j <= (sum / 2); j++) {
                if(((j - nums[i]) >= 0) && (valuePossible[i - 1][j - nums[i]])) {
                    valuePossible[i][j] = true;
                } else {
                    valuePossible[i][j] = valuePossible[i - 1][j];
                }
            }
        }

        return valuePossible[nums.size() - 1][sum / 2];
    }
};