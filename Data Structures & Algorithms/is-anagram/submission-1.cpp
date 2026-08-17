class Solution {
public:
    bool isAnagram(string s, string t) {
        // Is there a restriction on what kinds of chracters the strings hold?
        
        // So, the definition I read about an anagram tells me that a string is another string's anagram if the 2 of them have exactly same unique characters in them and the frequencies of each of those characters match in both the 2 strings.
        // Thus, this is the approach that comes to my mind that we would calculate the number of times each character occurs in each of the 2 strings and just compare the frequencies of a character occurring in both the strings.
        // If the count of each and every character matches in both the strings then the 2 strings are anagrams of each other.

        vector<int> charFreqOfS(26, 0); // There are only 26 characters we are monitoring for now.
        vector<int> charFreqOfT(26, 0);

        for(char c: s) {
            charFreqOfS[c - 'a']++;
        }

        for(char c: t) {
            charFreqOfT[c - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(charFreqOfS[i] != charFreqOfT[i]) {
                return false; // count of ith alphabet in string S does not match the count of ith alphabet in string T.
            }
        }

        return true; // All the Character counts match apparently.
    }
};