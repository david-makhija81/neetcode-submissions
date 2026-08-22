class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // If I keep appending one digit after another from the digits array, I'll make a number we are dealing with, right?
        // Where does the digit with 1's place lie - is it at the 0th index or at the last index?
        // What is the range of this large integer? Can it be negative?

        // So, the 1's place digit lies at the last index, right?
        // We must just follow the standard addition algorithm.
        // Add 1 to the least significant digit, calculate the carry, separate the carry from this sum, store the rest of sum in this digit's place transfer the carry forward and repeat this process until either the carry is 0 or the digits run out of place.
        // If the carry becomes 0 then we do nothing, because there's nothing more to add, but if the carry isn't 0 and we have gone through every digit - then we have surely run out of digits to add carry to them thus we append an additional digit in front of the most significant place in the integer and this additional digit nothing but the carry.

        int carry = 1;

        for(int i = (digits.size() - 1); (i >= 0) && (carry > 0); i--) {
            int digitSum = digits[i] + carry;
            digits[i] = (digitSum % 10);
            carry = digitSum / 10;
        }

        if(carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};