class Solution {

    void exploreAllCombinations(vector<int>& currCombination, int target, int sum,
                        vector<vector<int>>& selectedCombinations, vector<int>& candidates, int idx) 
    {
        if(target < sum) {
            return; // The currCombination's sum has surpassed the target - thus can no longer be considered.
        }

        if(target == sum) {
            selectedCombinations.push_back(currCombination); // The current combination qualifies for selection thus we push it into the answer.
            return; // Anything pushed further will only exceed the target.
        }

        if(idx >= candidates.size()) {
            return; // There remain no more elements to be considered.
        }

        currCombination.push_back(candidates[idx]); // Consider the current element until it overflows the target.
        exploreAllCombinations(currCombination, target, sum + candidates[idx], 
                    selectedCombinations, candidates, idx); // We will consider the current element until it overflows the traget so as to explore all possible combinations.
        currCombination.pop_back(); // pop the last pushed i.e. candidates[idx] the current index skip this index and let's consider the next element.

        exploreAllCombinations(currCombination, target, sum, 
                    selectedCombinations, candidates, idx + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Can one element be chosen more than once?
        // Is there a limit on the number of times an integer can be chosen?

        // I suppose the solution here seems kind of obvious,
        // We go through the array and standing at an element, we either choose the element to carry forward in the sequence or we drop it and move to the next element.
        // But, we need to explore all the combinations. Thus, it makes sense to include an element that many number of times until the total exceeds or becomes equal to the target.
        // After that we keep on removing the elements one after another and keep considering more elements for the same.

        vector<int> currCombination; // We keep adding and removing elements into it and track its sum to explore all the possible combinations.
        vector<vector<int>> selectedCombinations; // This stores all the combinations that pass the conditions and explored till now by us.
        
        exploreAllCombinations(currCombination, target, 0, selectedCombinations, candidates, 0);

        return selectedCombinations;
    }
};