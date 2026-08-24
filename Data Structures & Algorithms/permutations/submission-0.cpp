class Solution {

    void makePermutations(vector<int>& currPermutation, vector<vector<int>>& permutations, vector<int>& nums, vector<bool>& chosen) {
        if(currPermutation.size() == nums.size()) {
            permutations.push_back(currPermutation);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!chosen[i]) {
                chosen[i] = true;
                currPermutation.push_back(nums[i]);
                makePermutations(currPermutation, permutations, nums, chosen);
                currPermutation.pop_back();
                chosen[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // So, we have to make permutations of a given array and we have to return an answer that contains all the permutations of that array.
        // To make a permutation, all you do is choose an element out of the n given elements, place it at the first position, now move to the second position and choose from the (n - 1) remaining elements place it here and repeat this until you have used the entire n elements.
        // Permutations also take into consideration the position of an element, so if you chose one element for the first position then that permutation would differ from any other permutation where any other element is chosen for the first position.
        // Thus, we should go position by position choosing one element at a time mark it as chosen so that it is not chosen for other position and store all the permutations in an array.

        vector<vector<int>> permutations;

        vector<int> currPermutation;

        vector<bool> chosen(nums.size(), false);

        makePermutations(currPermutation, permutations, nums, chosen);

        return permutations;
    }
};