class Solution {
public:
    int jump(vector<int>& nums) {
        // So, we have an array of elements and we have to reach the last index where at each position we can jump up to the the number written at that position in nums.
        // The straightforward approach would be to try out all the paths and written the minimum of all those paths - but this approach might take a lot of operations and might even try out redundant subpaths.
        // Another approach that might be valid here is to find a nice heuristic maybe that helps us look for the next best jump alternative and we just follow the path this approach leads us to and return it's length.
        // What is the best heauristic here? As we have to kind of make the least number of jumps - it makes sense to choose the positions that shoot you of the farthest so that you can travel the most distance in just one jump.
        // We'll just do that, we will jump up to a position, given the value at that position we get the range of distance we can travel from here and out of this range we select the position that will shoot us off the farthest.
        // We determine the next position we go there and repeat the process until we reach the last index.

        int left = 0, right = 0;
        int jumps = 0;

        while(right < (nums.size() - 1)) {
            int farthest = 0;
            for(int i = left; i <= right; i++) {
                farthest = max(farthest, nums[i] + i);
            }

            left = right + 1;
            right = farthest;

            jumps++;
        }

        return jumps;
    }
};