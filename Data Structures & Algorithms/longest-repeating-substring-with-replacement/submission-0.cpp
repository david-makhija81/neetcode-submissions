class Solution {
public:
    int characterReplacement(string s, int k) {
        // Does it require any kind of minimum gap between characters that we can replace?

        // If we take a random substring of the actual string having n elements, and the most occurring element in that string occurs about m times, such that m + k = n 
        // In this case we can say with complete surity that this substring can easily have the same characters after converting any characters other than the most occurring character into the most occurring character.
        // We keep a window enclosing a substring that maintains the count of most occurring element to be equal to or greater than n - k; where n is the number of elements in the substring and k is the number of allowed operations.
        // The maximum length of this window is our answer.

        int windowLeft = 0, windowRight = 0; // The window is empty in the beginning.
        vector<int> charFreq(26, 0); // This vector maintains the count of all the elements in the window.

        int ans = 0;

        while(windowRight < s.size()) {
            charFreq[s[windowRight] - 'A']++; // Adding an element into the window.
            windowRight++;

            int maxOccurrence = *max_element(charFreq.begin(), charFreq.end());
            while(maxOccurrence < (windowRight - windowLeft - k)) {
                charFreq[s[windowLeft] - 'A']--; // Remove a character from the array.
                windowLeft++;
                maxOccurrence = *max_element(charFreq.begin(), charFreq.end());
            }

            ans = max(ans, windowRight - windowLeft);
        }

        return ans;
    }
};