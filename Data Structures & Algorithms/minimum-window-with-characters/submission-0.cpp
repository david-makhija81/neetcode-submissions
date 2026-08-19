class Solution {

    bool canShrinkTheWindow(vector<int>& charFreqOfT, vector<int>& charFreqOfSub, char c) {
        int removeCharAscii = static_cast<int>(c);

        charFreqOfSub[removeCharAscii]--;

        for(int i = 0; i < 256; i++) {
            if(charFreqOfT[i] > charFreqOfSub[i]) {
                charFreqOfSub[removeCharAscii]++;
                return false;
            }
        }

        charFreqOfSub[removeCharAscii]++;
        return true;
    }

    bool sContainsT(vector<int>& charFreqOfT, vector<int>& charFreqOfSub) {
        for(int i = 0; i < 256; i++) {
            if(charFreqOfT[i] > charFreqOfSub[i]) {
                return false;
            }
        }

        return true;
    }

public:
    string minWindow(string s, string t) {
        // For example, if t = "at" and s = "asrtklysfart" then the answer would be "art"?
        // What kind of characters does these strings have?

        // As far as I understand this problem, we need to find a substring of s that has all the characters with the same count that are there in the string t. 
        // We have to find the substring that has minimum length out of all such substrings.
        // We go through the characters in string s, as soon as we find a charcter in s that is also in t, when I find that character - I will start the substring from there keeping adding elements until all the characters from t are there in that substring.
        // We record that substring along with it's length, so we can find the minimum length substring of this sorts.
        // When all the characters are the in the substring we try to decrease the length of this substring until the point where we have all the characters of t in that substring.

        vector<int> charFreqOfT(256, 0);   // To make matching the string easier
        vector<int> charFreqOfSub(256, 0);   // To make matching the string easier

        for(char c: t) {
            int idx = static_cast<int>(c);

            charFreqOfT[idx]++;
        }

        int left = 0, right = 0; // current window bounds.
        int windowLeft = 0, windowRight = 0; // desired window bounds.
        string ans = "";
        bool found = false;

        while(right < s.size()) {
            int rightCharAscii = static_cast<int>(s[right]);

            charFreqOfSub[rightCharAscii]++;
            right++;

            while((left < right) && canShrinkTheWindow(charFreqOfT, charFreqOfSub, s[left])) {
                int leftCharAscii = static_cast<int>(s[left]);

                charFreqOfSub[leftCharAscii]--;
                left++;
            }

            if(sContainsT(charFreqOfT, charFreqOfSub) && (((right - left) < (windowRight - windowLeft)) || (!found))) {
                windowLeft = left;
                windowRight = right;
                found = true;
            }
        }

        ans = s.substr(windowLeft, windowRight - windowLeft);

        return ans;
    }
};