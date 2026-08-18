class Solution {
public:
    int hammingWeight(uint32_t n) {
        // Can the input be negative or zero?

        // So, if the input is the number 3 then it's binary representation would look something like 11 as it's apparent this binary representation has 2 set bits, right?
        // I do know a way to figure out if the rightmost bit is set or not, we can either do a bitwise 'and' operation with the integer; if the rightmost bit of the given integer is 0 then automatically the answer of this and operation would be 0 else if the rightmost bit is 1 then the answer would be 1.
        // Thus, with this operation we can count all of the set bits by shifting all of the bits to the right after checking the rightmost bit.

        int bitCount = 0; // This stores the number of bits, we keep updating it while counting the bits.

        while(n > 0) { // This signifies there are set bits left in the input integer
            if(n & 1) { // This signifies the righmost bit is set
                bitCount++;
            }

            n = n >> 1; // Shifting the rest of the bits to the right by 1.
        }

        return bitCount;
    }
};
