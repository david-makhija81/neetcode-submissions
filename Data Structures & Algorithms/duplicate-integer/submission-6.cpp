class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size() < 2) { // This automatically rules out the possibility of having any duplicates in the array.
            return false;
        }

        // Are the numbers arranged randomly or are the sorted according to their values?

        // Simplest approach would be to search for an equal value element for every element in the array
        // But this approach would cost about O(N^2) time because for each element we are search the entire array.

        // A cheaper approach with respect to time would be to first sort the array, this all the duplicates are pushed together adjacent to each other.
        // Thus, we can just go through the sorted array comparing each element with it's neighbour if they match - the array contains duplicates otherwise it does not.

        sort(nums.begin(), nums.end()); // This step acts as the bottleneck for the solution and it takes O(N*log(N)) because comparing neighbours throughout the array only costs like O(N).

        for(int i = 0; i < (nums.size() - 1); i++) { // We are comparing each element with the element placed just next to it thus we go till the second element only to avoid runtime errors.
            if(nums[i] == nums[i + 1]) {
                return true;    // The array does contain duplicates
            }
        }

        return false; // If no 2 neighbours match even after going through the entire array then that means there are no duplicates in the array thus here we return false
    }
};