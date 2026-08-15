class Solution {

    bool isAlphaNumeric(char c) {
        return (
                ((c >= '0') && (c <= '9')) || 
                ((c >= 'a') && (c <= 'z')) || 
                ((c >= 'A') && (c <= 'Z'))
            );
    }

    bool isUpperCase(char c) {
        return ((c >= 'A') && (c <= 'Z'));
    }

    char toLowerCase(char c) {
        return ((c - 'A') + 'a');
    }

public:
    bool isPalindrome(string s) {
        // Do we need to treat the uppercase and lowercase letters the same?
        
        // We can make a new expression by processing the input expression.
        // While making the new expression we filter out the non-alphanumeric characters.
        // and we only keep either the uppercase or lowercase alphabets.
        // Then we can easily examine if the new string is a palindrome or not via a 2-pointer approach.

        string onlyAlphaNumeric = ""; // In the new beginning it is empty, we fill the string as we go about filtering the original string.

        for(char c: s) {
            if(isAlphaNumeric(c)) {
                if(isUpperCase(c)) {
                    c = toLowerCase(c);
                }

                onlyAlphaNumeric.push_back(c); // only push the alphanumeric lowercase characters in the new string.
            }
        }

        int left = 0, right = onlyAlphaNumeric.size() - 1; // Starting from the 2 ends of the expression we keep comparing the characters at the 2 ends of the expression if the 2 sides match we return true else we return false.

        while(left < right) {
            if(onlyAlphaNumeric[left] != onlyAlphaNumeric[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};