class Solution {
public:
    string longestPalindrome(string s) {
        // So, the straightforward approach to this would be to try all substring of a string individually check if they are a palindrome and then update the longest length.
        // For example, if we have a substring "ababa", then we check the substrings in the following order:
        // "a", "ab", "aba" -> update longest length to 3, "abab", "ababa" -> update the longest length to be 5, "b", "ba", "bab", "baba", "a", "ab", "aba", "b", "ba", "a"
        // We did get an answer to the problem via the above approach.
        // But, there's a catch to that above approach and that is that we used checked for some substrings more than once.
        // For example, take the substring starting from index 2 and containing only one character, we used 3 times in a palindrome and if we talk about the "bab" we used it twice and talking the substring "ba" which starts from index 1 we used it in the middle of about 2 substrings.
        // Thus, to reduce the number operations we must store the result of every substring and use it when we feel the need to do so.

        vector<vector<int>> palinLength(s.size(), vector<int>(s.size(), 0));

        int maxLength = 0;
        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            palinLength[i][i] = 1;
            if(maxLength < palinLength[i][i]) {
                maxLength = palinLength[i][i];
                ans = s.substr(i, 1);
            }
        }

        for(int i = 0; i < (s.size() - 1); i++) {
            if(s[i] == s[i + 1]) {
                palinLength[i][i + 1] = 2;
                if(maxLength < palinLength[i][i + 1]) {
                    maxLength = palinLength[i][i + 1];
                    ans = s.substr(i, 2);
                }
            }
        }

        for(int length = 3; length <= s.size(); length++) {
            for(int i = 0; (i + length - 1) < s.size(); i++) {
                int j = i + length - 1;

                if((s[i] == s[j]) && (palinLength[i + 1][j - 1] > 0)) {
                    palinLength[i][j] = palinLength[i + 1][j - 1];

                    if(maxLength < length) {
                        maxLength = length;
                        ans = s.substr(i, length);
                    }
                }
            }
        }

        return ans;
    }
};