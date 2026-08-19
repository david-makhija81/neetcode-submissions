class Solution {
public:
    bool canJump(vector<int>& nums) {
        // I need to figure out if I can reach the last position of an array or not given the jump capability of each cell.
        // Whether if I can reach a cell or not is decided by whether before this cell exists a cell that has enough jump capacity to launch me to this cell.
        // So, if we start looking from our goal right away - like if we stand at the last position in the array and we look at the cells before it to figure out if I could have reached here from any of the cells before given their jump capacities, I would then go there trying to trace a path from the first position all the way to the last position if I am able to do so then a path is possible else the path is not possible.

        int currPos = nums.size() - 1; // We start from last

        while(currPos > 0) { // Until we reach the start of the array
            int nextPos = currPos - 1;

            while((nextPos >= 0) && (nums[nextPos] < (currPos - nextPos))) {
                nextPos--;
            }

            currPos = nextPos;
        }

        return (currPos == 0);
    }
};