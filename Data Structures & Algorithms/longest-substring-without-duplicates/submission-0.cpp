class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // What kind of characters does this string contains only alphabets or more than that?
        
        // The longest substring that does not have any duplicate characters would only have unique characters of the string.
        // So, what if one counts all the unique characters and returns that count but that approach would fail in the case "abbc" as a substring needs to be contiguous and the longest substring of this string would only have a length of 2 and our substring would give an answer of 3.
        // Thus, another approach is to create a window inside the string which does contain any as we go through the string we keep on adding characters to it and we keep the count of every character that got added to monitor if we added a character more than once.
        // And as we add more characters to the window - if a character does get added more than once than we keep shrinking the window until that character's count drops back to one again.
        // We maintain a variable to store the maximum length recorded of that window and at the end we return that record.

        int maxWindowLength = 0;
        int windowLeft = 0, windowRight = 0; // In the start the window is empty.
        set<int> charFreq;

        while(windowRight < s.size()) {
            while(charFreq.find(s[windowRight]) != charFreq.end()) {
                charFreq.erase(s[windowLeft]);
                windowLeft++; // Shrinking window until the new character's count drops back to one in the window.
            }

            charFreq.insert(s[windowRight]);  // Add an element to the window.

            windowRight++;

            maxWindowLength = max(maxWindowLength, (windowRight - windowLeft));\
        }

        return maxWindowLength;
    }
};