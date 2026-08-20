class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Does the array contain negative elements?
        // Does the array contain duplicates?
        // Are the elements arranged in some specific order like non-descending or something?

        // So, we have to make triplets - right?
        // For the simplest take we could take one element as the element of the triplet choose another element for the triplet and then find a 3rd element such that it it makes the sum of these 3 elements equal to 0.
        // If the array has a length of n then the above approach would require O(n^3) operations
        // Let's think of a solution that requires lesser number of operations, maybe if the array is sorted then it becomes easy to find an element of a specific value in the array and likewise this might help us in the solution.
        // So, after sorting the array - we choose a random element and for this element we need to find a pair that when summed up with it gives us 0.
        // So, it's clear that we know the value of pair sum we want to look for i.e. the negative of this element; thus from here on we can maybe a 2-pointer approach increment the left pointer when the pair sum falls short of the target and vice-versa for the right pointer.
        // For example, if we have an array like [-3, -3, -2, -1, 1, 1, 2], for the first element we start selecting elements from left to right.
        // First, select -3 and the left and right pointer point at index 1 & index 6 at the beginning; the pair sum at this point is lesser than the negative of -3 thus keep on increasing the left pointer until we reach the index 4 at which point we have found our triplet - we store it somewhere and move on to find new pairs.
        // But because we have not to include any duplicates we increment the left pointer until the value differs from the last triplet included value that is 1 in this case - because even if one element changes the whole triplet assumes a new face.
        // After this, the pair window collapses as both the left and right pointers collide at index 6.
        // And now we pick a new element to be the first element of the triplet and we make sure that this element is not equal to the previously chosen element so as to not include any duplicate triplets.
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int firstIdx = 0;

        while(firstIdx < nums.size() - 2) {
            int secondIdx = firstIdx + 1, thirdIdx = nums.size() - 1;
            int target = (-1) * nums[firstIdx];
            while(secondIdx < thirdIdx) {
                if((nums[secondIdx] + nums[thirdIdx]) == target) {
                    ans.push_back({nums[firstIdx], nums[secondIdx], nums[thirdIdx]});
                    while((nums[secondIdx] == ans.back()[1]) && (secondIdx < thirdIdx)) {
                        secondIdx++;
                    }
                } else if((nums[secondIdx] + nums[thirdIdx]) < target) {
                    secondIdx++;
                } else {
                    thirdIdx--;
                }
            }

            firstIdx++;
            while((firstIdx < nums.size() - 2) && (nums[firstIdx] == nums[firstIdx - 1])) {
                firstIdx++;
            }
        }

        return ans;
    }
};