class Solution {

    bool isPermutation(vector<int>& charCountS1, vector<int>& charCountWin) {
        for(int i = 0; i < 26; i++) {
            if(charCountS1[i] != charCountWin[i]) {
                return false;
            }
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        // So, permutation of a string is that string's character rearranged in a different fashion other than the one it is arranged in right now.
        // Thus, if the permutation of a string s1 lies inside s2 then that permutation must be of the same length as the string s1 itself - thus, we must check for all substrings of s2 that have the same length as s1 if they are a permutation of s1.
        // And, on another note if one string is a permutation of the other one then they must have same unique characters in them with same count. Thus we keep a window that matches the length of string s1 and we slide it through the string s2 we keep updating the count of each character in that window if the count of every character in both the window and the string match then this window is the permutation of given and this window inside s2 thus we return true, else if after looking at all the windows - no window comes out to be the permutation of the other string then we return false.

        int windowLeft = 0, windowRight = 0;

        vector<int> charCountS1(26, 0);
        vector<int> charCountWin(26, 0);

        while(windowRight < s2.size()) {
            if(windowRight < s1.size()) {
                charCountS1[s1[windowRight] - 'a']++;
                charCountWin[s2[windowRight] - 'a']++;

                windowRight++;

                if(windowRight == s1.size()) {
                    if(isPermutation(charCountS1, charCountWin)) {
                        return true;
                    }
                }
            } else {
                charCountWin[s2[windowRight] - 'a']++;

                windowRight++;

                charCountWin[s2[windowLeft] - 'a']--;

                windowLeft++;

                
                if(isPermutation(charCountS1, charCountWin)) {
                    return true;
                }
            }
        }

        return false;
    }
};