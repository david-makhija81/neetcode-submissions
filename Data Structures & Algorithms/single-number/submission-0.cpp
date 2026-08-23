class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // So, I have an array of integers where every element occurs exactly twice except for one element which occurs only once.
        // And we have to identify the element that occurs only once.
        // One solution for this could be to sort the array first which pushes the elements with same value consecutive to each other in the array.
        // And then compare every second element with it's neighbour, if does not match with it's neighbour then this is the answer. This solution requires O(n*log(n)) number of operations and O(log(n)) amount of extra space.
        // There must be another solution or operation which reduces the Time & Space Complexity
        // If there was an operation which when applied to every element in the array cancelled out only duplicates then at the end of that operation we would get our answer.
        // For example, if we had an array like [1, 2, 1, 3, 2] then that operatiion would cancel out 1 with 1, 2 with 2 but as there is no duplicate of 3 thus 3 would be left intact.
        // And I have just the operation for that and that is the xor operation which results in 0 when put between duplicates.
        // So, we will keep a placeholder which gets xored with every element in the array and at the end we get our answer in that placeholder only.

        int entireXor = 0;

        for(int num: nums) {
            entireXor ^= num;
        }

        return entireXor;
    }
};