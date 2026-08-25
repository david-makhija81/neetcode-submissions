class Solution {

    bool isValid(char c1, char c2) {
        return ((c1 == '1') || ((c1 == '2') && ((c2 - '0') <= 6)));
    }

public:
    int numDecodings(string s) {
        // So, the message has already been encoded and it might decoded in multiple ways let's say we have "111" - so this encoding can be decoded in multiple ways like [11, 1] -> "KA" or [1, 11] -> "AK" or [1, 1, 1] -> "AAA"
        // And, we have to figure out how many ways can this string be decoded in.

        // One way we can do this, is to try creating decodings by taking characters either individually or in pairs. taking one number's encoding at a time and building the rest of the result upon it, 
        // For example, we have the example [1, 1, 1] we first take in this example 1 in the beginning the decoding for this is "A" we move on to the next element considering each element individually and at the end we get the decoding "AAA" we found one distinct version we increment the count of number of possible decodings.
        // We try to take the last integer in a pair with a successive positioned integer to it, we do not find any integer positioned successive to it, thus we abort the pairing for this integer and move back to the previous integer.
        // Then we reach at the index 1 and we try to pair it with the next integer trying to make another decoding and we get [1, 11] -> "AK".
        // And we keep doing this until we have figured out all the possible decodings.
        // But this would take a lot of time, thus one we can improvise is to avoid visiting the already solved subproblems and build the solution from ground up.
        // While standing at an integer, we figure out the number of ways it can be decoded up till this length encoding.

        if(s[0] == '0') {
            return 0;
        }

        if(s.size() == 1) {
            return 1;
        }

        vector<int> decodingCount(s.size(), 0);

        decodingCount[0] = 1;

        decodingCount[1] = 
            ((s[1] == '0') ? 0 : 1) + 
            (isValid(s[0], s[1]) ? 1 : 0);

        for(int i = 2; i < s.size(); i++) {
            decodingCount[i] = 
                ((s[i] == '0') ? 0 : decodingCount[i - 1]) +
                (isValid(s[i - 1], s[i]) ? decodingCount[i - 2] : 0);
        }

        return decodingCount[s.size() - 1];
    }
};