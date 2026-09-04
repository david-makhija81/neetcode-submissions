class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // Do we have a guarantee that both the strings will have equal number of characters in them? I mean, the length of both the strings match with each other.
        // so we have to interleave the word, one, the characters of word 1, and the characters of word 2.
        // and we have to start the interleaving with word one, the characters of word one.
        // and what do we do if, if the, if after interleaving all the elements, let's suppose one string does not, is not left with any characters to be interleaved further, but the other string still has characters left? Do we just append those characters to the back of the to the back of the string, we have to return, or what do we do with them?
        // so I suppose the road from here is pretty straightforward. We just start interleaving the characters, and if one string has no characters left, and the other string still has characters left, we just append the remaining number of characters to the ancestring, and that's how we make our result.

        string ans = "";
        int ptr1 = 0, ptr2 = 0;

        while((ptr1 < word1.size()) && (ptr2 < word2.size())) {
            ans.push_back(word1[ptr1]);
            ptr1++;
            ans.push_back(word2[ptr2]);
            ptr2++;
        }

        while(ptr1 < word1.size()) {
            ans.push_back(word1[ptr1]);
            ptr1++;
        }

        while(ptr2 < word2.size()) {
            ans.push_back(word2[ptr2]);
            ptr2++;
        }

        return ans;
    }
};