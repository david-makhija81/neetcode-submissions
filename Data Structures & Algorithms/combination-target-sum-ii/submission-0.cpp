class Solution {

    void countCombinations(int idx, int target, vector<int>& currCombination, int sum, vector<int>& candidates, vector<vector<int>>& ans) {
        if(sum == target) {
            ans.push_back(currCombination);
            return;
        }

        if((sum > target) || (idx == candidates.size())) {
            return;
        }

        currCombination.push_back(candidates[idx]);
        countCombinations(idx + 1, target, currCombination, sum + candidates[idx], candidates, ans);
        currCombination.pop_back();

        while((idx < (candidates.size() - 1)) && (candidates[idx + 1] == candidates[idx])) {
            idx++;
        }
        countCombinations(idx + 1, target, currCombination, sum, candidates, ans);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Are all the candidates unique and distinct?
        // How do you determine if one combination is different from another one? Is it all about the elements in the combinations or does their order also matter?
        
        // So, we have to figure out distinct combinations that sum up to target.
        // So, 2 combinations are same if they have the same elements irrespective of the order they are put in.
        // I suppose this problem must be done in steps like we start with just one length subarray we choose if this element should be included in the combination or not, this way we make a subcombination which would come handy in further element considerations.
        // So, we might have made multiple subCombinations in the previous step and we'll make some more by taking into consideration whether the current element should be considered in the subCombination or not, we do this until we have considered all the elements or we have considered all the combinations that sum up to target or fall short of it, if a combination sums up to target we include it in the ans else we reject it.

        vector<vector<int>> ans;

        vector<int> currCombination;

        sort(candidates.begin(), candidates.end());

        countCombinations(0, target, currCombination, 0, candidates, ans);

        return ans;
    }
};