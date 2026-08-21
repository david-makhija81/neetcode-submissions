class Solution {
public:
    int getSum(int a, int b) {
        // As we cannot use the + and - operations, thus we have to look at other operations that do a similar job.
        // Let's first look at how addition actually works - In order to add 2 numbers we follow a simple algorithm where we add the digits in the 2 numbers that belong to the same place, we take the digit from the first place of this sum put it in the resulting sum at that place only, and at the end we store the carry somewhere & move to the next digits.
        // We usually use algorithm for numbers in base 10.
        // But to do this in base 10 we'll need to use the addition operation or subtraction operation.
        // But, if we try it in base 2 (binary) we can use the binary operations without even touching the '+' or '-' operations.
        // For example if we take the xor of 2 bits then it gives us the bit for that place only and the '&' operation of 2 bits gives us the carry.
        // For example adding 1 & 1 gives '10' where '1 ^ 1 = 0' bit for 1's place in binary and '1 & 1 = 1' carry for the next bit.
        
        while(b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};
