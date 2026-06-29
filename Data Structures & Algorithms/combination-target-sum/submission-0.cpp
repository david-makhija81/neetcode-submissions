class Solution {

    void determineCombinations(vector<int>& candidates, int currIdx, int target, vector<int> currCombination, int sumTillNow, vector<vector<int>>& combinations) {
        if((sumTillNow >= target) || (candidates.size() == currIdx)) {
            if(sumTillNow == target) {
                combinations.push_back(currCombination);
            }

            return;
        }

        currCombination.push_back(candidates[currIdx]);
        determineCombinations(candidates, currIdx, target, currCombination, sumTillNow + candidates[currIdx], combinations);
        currCombination.pop_back();
        determineCombinations(candidates, currIdx + 1, target, currCombination, sumTillNow, combinations);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> currCombination;

        determineCombinations(candidates, 0, target, currCombination, 0, combinations);

        return combinations;
    }
};