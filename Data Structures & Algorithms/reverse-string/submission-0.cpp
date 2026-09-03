class Solution {
public:
    void reverseString(vector<char>& s) {
        // if I had to reverse a sequence of characters, which is a string, what I would do is, I would place it in front of the mirror.
        // this mirror image reverses the order of characters they were placed in initially.
        // so the last character becomes the first character, the second last character becomes second character, and so on, and the 1st character becomes the last character.
        // thus, put another way, it is just swapping the, the characters on the opposite ends, the first character with the last character, with the second last character, until we are out of possible swaps, that is until we reach the middle.
        // and this is what will do in our algorithm, will start from both the ends, we swap those characters. We make our way to the middle. We keep swapping elements, and the resultant would be the reversed string.

        int left = 0, right = s.size() - 1;

        while(left < right) {
            char c = s[left];
            s[left] = s[right];
            s[right] = c;

            left++;
            right--;
        }
    }
};