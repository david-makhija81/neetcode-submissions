class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charFrequency;

        int leftEnd = 0, result = 0;

        for(int rightEnd = 0; rightEnd < s.size(); rightEnd++) {
            charFrequency[s[rightEnd]]++;

            while(charFrequency[s[rightEnd]] > 1) {
                charFrequency[s[leftEnd]]--;
                leftEnd++;
            }

            result = max(result, rightEnd - leftEnd + 1);
        }

        return result;
    }
};