class Solution {

    void fillThePowerSet(int idx, vector<int>& currSubset, vector<int>& nums, vector<vector<int>>& powerSet) {
        if(idx == nums.size()) {
            powerSet.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[idx]);
        fillThePowerSet(idx + 1, currSubset, nums, powerSet);
        currSubset.pop_back();
        fillThePowerSet(idx + 1, currSubset, nums, powerSet);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // So, for a given set of elements we have to return the powerset of that sequence of numbers.
        // That is, the collection of all possible subsets of of that set.
        // To make a subset we choose a combination of elements from the original set and for each element we have a choice of whether to take it or leave it.
        // Thus, it makes sense to do this problem in steps like first we start with the set of length 1 - make all subsets by including or not including the only element in the subarray of length 1.
        // We then proceed with the result and make further subsets from the array of length 2 by either including or not including the last element in the subsets that we calculated earlier.
        // We repeat these steps until we have the subsets of the original set and voila, we have our power set.

        vector<vector<int>> powerSet;

        vector<int> currSubset;

        fillThePowerSet(0, currSubset, nums, powerSet);

        return powerSet;
    }
};