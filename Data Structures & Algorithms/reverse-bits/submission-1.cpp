class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // How many number of bits are there in n?
        // Is it a 32 bit integer or a 64 bit integer?
        // Can this integer n be negative?

        // I do not know a direct way to reverse the bits of an integer, but I do know a way to reverse a string or an array per say.
        // Because they are just arrangement of elements and one can easily traverse through these arrangements as well as alter the elements at any and every position.
        // Thus, if we could convert an integer into a sequence of bits then we can first convert that integer into string representation of it's bits, after that we could we could reverse that string and convert that reversed string back into an integer.

        string nBinaryRepresentation = "";

        for(int i = 0; i < 32; i++) { // Because it is a 32 bit integer.
            string nextBit = "0"; // By default it is zero, we turn it to 1 if there's a need.

            if(n & 1) {
                nextBit = "1";
            }

            nBinaryRepresentation = nextBit + nBinaryRepresentation;

            n = n >> 1;
        }

        // cout << nBinaryRepresentation << endl;

        int leftPtr = 0, rightPtr = 31;

        while(leftPtr < rightPtr) {
            char c = nBinaryRepresentation[leftPtr];

            nBinaryRepresentation[leftPtr] = nBinaryRepresentation[rightPtr];

            nBinaryRepresentation[rightPtr] = c;

            leftPtr++;
            rightPtr--;
        }

        // cout << nBinaryRepresentation << endl;

        uint32_t ans = 0;

        for(int i = 0; i < 32; i++) {
            ans = ans << 1;

            if(nBinaryRepresentation[i] == '1') {
                ans = (ans | 1);
            }
        }

        return ans;
    }
};
