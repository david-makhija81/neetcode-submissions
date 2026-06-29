class Solution {

    bool isNotAlphaNumeric(char c) {
        if((((c - 'a') < 26) && ((c - 'a') >= 0)) || (((c - 'A') < 26) && ((c - 'A') >= 0)) || (((c - '0') < 10) && ((c - '0') >= 0))) {
            return false;
        }

        return true;
    }

    char lowerCase(char c) {
        if(((c - 'a') < 26) && ((c - 'a') >= 0)) {
            return c;
        }

        if(((c - '0') < 10) && ((c - '0') >= 0)) {
            return c;
        }

        c = ((c - 'A') + 'a');

        return c;
    }
    
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while((left < s.size()) && isNotAlphaNumeric(s[left])) {
            left++;
        }

        while((right >= 0) && isNotAlphaNumeric(s[right])) {
            right--;
        }

        while(left < right) {
            if(lowerCase(s[left]) != lowerCase(s[right])) {
                return false;
            }

            left++;
            right--;

            while((left < s.size()) && isNotAlphaNumeric(s[left])) {
                left++;
            }

            while((right >= 0) && isNotAlphaNumeric(s[right])) {
                right--;
            }
        }

        return true;
    }
};
