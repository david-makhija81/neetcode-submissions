class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // So, as there are 2 strings and from each string we can choose any number of elements while preserving the order and we get a subsequence of that string.
        // We have to find the length of longest susequence which occurs in both the strings.
        // So, the straightforward solution to this problem would be to try making all the subsequences compare one with another string's subsequence and if they match we store it's length for longest subsequence.
        // But the above approach might require a lot of operations, Thus we need to look for an approach that requires lesser time.
        // One other approach that might work here is to go step by step, in each step we take the lengths of the 2 strings and we try to construct their common subsequences store the length of longest one and then use these values to find the answer for successive steps.

        vector<vector<int>> lengthOfLCS(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        int ans = 0;

        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    lengthOfLCS[i][j] = lengthOfLCS[i - 1][j - 1] + 1;
                } else {
                    lengthOfLCS[i][j] = max(lengthOfLCS[i - 1][j], lengthOfLCS[i][j - 1]);
                }
                ans = max(ans, lengthOfLCS[i][j]);
            }
        }

        return ans;
    }
};