class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Are the elements in the nams are resorted in any order?
        // So the approach that comes to my mind is that we go through the array, and as soon as we discover, we keep 2 pointers, one that goes through each and every element of the array, explores the non-explode elements, and the other one that, uh, That, you know, um, that is keeping the, that is keeping track of the K unique elements.
        // So as soon as we, as soon as the pointer that is going through the entire array, encounters, an element that has not been yet discovered, or put it another way, that does not match with the previous element, so obviously this is a new element that we have kind of discovered.
        // Thus we add it into the, um, unique K elements and move on and keep adding them until we have explored all the elements.
        // To figure out if the new element that our pointer is at right now is unique or not, or if it has been encountered earlier or not, what we do is, we compare it with the last element that we added into a list of K unique elements.
        // If the new element, I mean, the actual element that we are in the list of the elements that we are exploring, is greater than the last element we added into our K, uh, into our list of unique K elements, then obviously, Then obviously, this is an element worth adding because any element before this last element in the list of K unique elements, um, would be lesser than this, thus this is different from every other element in the list.
        
        int j = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[j] < nums[i]) {
                nums[j + 1] = nums[i];
                j++;
            }
        }

        return (j + 1);
    }
};