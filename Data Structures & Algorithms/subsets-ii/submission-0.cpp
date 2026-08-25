class Solution {

    void makeSubsets(int idx, vector<int>& subset, vector<int>& nums, vector<vector<int>>& powerset) {
        if(idx == nums.size()) {
            powerset.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        makeSubsets(idx + 1, subset, nums, powerset);
        subset.pop_back();

        while((idx < (nums.size() - 1)) && (nums[idx] == nums[idx + 1])) {
            idx++;
        }

        makeSubsets(idx + 1, subset, nums, powerset);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // So, we have to explore all the combinations that can be made out of the given set of elements.
        // The set we are provided with does have duplicates. Thus, the powerset can contain duplicate subsets because of this.
        // For example: if we have the array [2, 1, 1] then if we first chose 1st and 2nd element and then 1st and 3rd element then in general sense both the two subsets must be different from each other but as the 2nd and 3rd are equal thus both the 2 subsets are equal as well.
        // Thus, if we consider similar elements only once and take different counts of them to make different subsets.
        // We will first sort the elements to push the elements with same value consecutive to each other.
        // And then while considering each element in a subset we take care that we only consider the counts of the same element differently and not to elements with same value differently.

        vector<int> subset;
        vector<vector<int>> powerset;

        sort(nums.begin(), nums.end());

        makeSubsets(0, subset, nums, powerset);

        return powerset;
    }
};