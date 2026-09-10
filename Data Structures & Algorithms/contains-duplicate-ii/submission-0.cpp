class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // so I have to identify elements placed at different positions that assume the same value, but are separated by at least K elements in between.
        // A simple straightforward solution for this could be to, uh, let's say I'm standing at an index I in the array, and I start checking, uh, from the element at position I plus K all the way up to the last element of the airing.
        // And if any of these elements from I plus K to the last element matches with this ith element. Then I return true for any index i, uh-huh.
        // Put another way, the Put another way, if we have K consecutive elements, K elements, placed one after another, then None of those K, none of those K elements must contain any, must contain any duplicates if they do not contain any duplicates, then we return false, if they do contain any duplicates, K consecutive elements, one placed after another, if they do contain any duplicates, Then we write away return true.
        // But is there  a time efficient way. That helps us figure out if any element repeats in a K-length window, so we will start with a K-length window, we will shift it along along the array from left to right, if some element repeats, I mean, if we encounter an element that was already there, In this K-length window, and it persists in the window with that duplicate, then we return true that there exists, duplicates within the position, difference of K places.
        // We can maybe have a hash set, which stores elements for us. The look up in that set is go of one and I believe insertion is also of one in that set. And with that said, we can monitor duplicates, add elements, remove them, as we move the window. further to the right.

        set<int> window;

        for(int i = 0; i < (nums.size()); i++) {
            if(window.size() > k) {
                window.erase(nums[i - k - 1]);
            }
            
            if(window.find(nums[i]) != window.end()) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }
};