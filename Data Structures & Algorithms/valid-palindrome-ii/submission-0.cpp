class Solution {
public:
    bool validPalindrome(string s) {
        // So we have to figure out if this string is palindrome, if like if this string becomes a palindrome, after we delete one character or do not delete it, like if it is initially a palindrome, that is all right, if it can become a palindrome after deleting one character, then obviously we will go with that approach.
        // And if it cannot turn into a palindrome, even after deleting one character, then we have to return false, right?
        // To check if a string is a palindrome or not, what we do is we keep two pointers on either ends of a string. We keep comparing the, The characters are those 2 pointers. We move them towards each other. We keep doing this until they reach the middle, and if all of them are equal.

        // I mean, in each turn, when we compare the characters at either end, if both the characters are. equal in each turn, then we return true else we return false, that means the string is not apparent on in that case.
        // We can do slight modifications in this elementary or primary algorithm, such that as we are come, uh, like going uh, through the array, comparing the, uh, comparing different characters at either ends uh, of the strings, uh, you may say. If one character, the if a character at either end does not match the other end, then maybe we can try skipping that character.

        // If we skip that character and only once, we get the chance to skip a character only once and even then and we can skip either of those characters. There's no compulsion on skipping one of any of, I mean, a fixed character. If we skipped either of those characters, and we result in a palant room, then we return through, else we return false.
        int left = 0, right = s.size() - 1;
        bool skipped = false;

        while(left < right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            } else if(!skipped) {
                skipped = true;
                if(s[left + 1] == s[right]) {
                    left++;
                } else if(s[left] == s[right - 1]) {
                    right--;
                } else {
                    // cout << "characters do not match  and the pointers are not skippable." << endl;
                    // cout << "left = " << s[left] << ", right = " << s[right];
                    break;
                }
            } else {
                // cout << "characters do not match, and no option to skip." << endl;
                // cout << "left = " << s[left] << ", right = " << s[right] << endl;
                // cout << "left + 1 = " << s[left + 1] << ", right + 1 = " << s[right + 1];
                break;
            }
        }

        if(left >= right) {
            return true;
        }
        
        left = 0, right = s.size() - 1;
        skipped = false;

        while(left < right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            } else if(!skipped) {
                skipped = true;
                if(s[left] == s[right - 1]) {
                    right--;
                } else if(s[left + 1] == s[right]) {
                    left++;
                } else {
                    // cout << "characters do not match  and the pointers are not skippable." << endl;
                    // cout << "left = " << s[left] << ", right = " << s[right];
                    break;
                }
            } else {
                // cout << "characters do not match, and no option to skip." << endl;
                // cout << "left = " << s[left] << ", right = " << s[right] << endl;
                // cout << "left + 1 = " << s[left + 1] << ", right + 1 = " << s[right + 1];
                break;
            }
        }

        if(left >= right) {
            return true;
        }

        return false;
    }
};