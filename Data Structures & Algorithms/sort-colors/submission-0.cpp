class Solution {
public:
    void sortColors(vector<int>& nums) {
        // so we have three colours, red, white, and blue, and the mutual order of these colours should be placed, then comes white, and then comes blue. And the ordering among themselves should be like all the red colours are placed together, all the blue colours are placed together, and all the white colours are placed together.
        // Thus, I can only think of one solution, and that is, 1st I keep the red ones at the leftmost part of the array, Then after that comes, uh, grouped together, white colours, then after that are grouped together, blue colours.
        // what I can see here is that? There is a mutual order between any two colours, so if two colours are of the same category, let's say two colours are red colours, if one of them occurs after the other one, because it is in place, then the 1st one cannot surpass the 2nd one, that is, if we have. red colours at index 0 and one, we cannot swap 0 and one because it must be in the resultant area, must be, uh, in order.
        // and if we try to deduct this order for let's say different colours, distinct colours, let's say we have red and white, then if white is placed at index 0 and red red is placed at index one, then obviously white should surpass red. I mean, in this case, what should be what would be best for us is to swap the places for white and red?
        // If we keep doing this along the array, we keep comparing these neighbours and if there is not the desired order, the desired order does not reflect in the in the already present sequence, then obviously we should swap those 2 neighbouring elements.
        // if we keep doing this for the array? Keep comparing the neighbouring elements, if they are out of order, we swap them, if we keep doing this, will eventually push the, will eventually push the red colours to the left of the array and blue colours to the right of the array, and obviously white wood, white wood occupy the middle of the array in that case.
        // one other thing we should notice here is if we could keep comparing the neighbouring elements and we keep swapping them if they are out of order, then eventually we would have pushed the element that belongs to the rightmost position of this array to that position only.
        // So we do not need to consider the last position in the next iteration when we uh, when we again, compare the neighbours, and this way will shrink, will keep shrinking the size of the array, in which we compare the neighbours until there's no array left to be to be checked for if it is in order or not.

        for(int i = (nums.size() - 1); i >= 0; i--) {
            for(int j = 0; j < i; j++) {
                if(nums[j] > nums[j + 1]) {
                    int tempPlaceHolder = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tempPlaceHolder;
                }
            }
        }
    }
};