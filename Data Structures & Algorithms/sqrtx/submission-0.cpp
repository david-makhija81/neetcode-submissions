class Solution {
public:
    int mySqrt(int x) {
        // So we need to figure out the square root of X, right?
        // Suppose square root of X to be returned is Y.. why is a whole number that is a nonnegative number? 
        // And the conditions are such that the square of Y is lesser than equal to X is it so?

        // In this case, what we can do is maybe there is a range in which this square root thing can lie.
        // And we may use binary search to We may use binary search to, you know, cut off one of the halves of this search range in each iteration so as to get closer and closer to the actual result.
        // The way we cut off the haves. Determines, do we even get to our goal or result or not?
        // The way I will cut this range in either of the halves is that if the current variable Y that is the middle element of this range is, you know? The square of the middle element of this range is lesser than equal to X, then obviously this could be an answer. to our problem.
        // So and I can even find answers beyond this value, this minimum value. So, the 2nd half of this, this range is of use to me because I can find my answer there.
        // NFD Middle value, the square of the middle value is greater than X, then obviously this is not the answer, and I will not even find any answer to the right of it. So I will have to cut off the right part of the area in order to find the answer in the left part of this range.
        // More, but the more complicated part is to uh, figure out the range.
        //  It becomes simple when we are given the range of X, so X is in between zero and two to the power, 31-1, does X is greater than zero, but always lesser than two to the power, 32, so square root of X, whatever it might be, is obviously lesser than 2 to the power, 16, because the square root of 2 to the power, 32 is obviously 2 to the power, 16.

        // So, this way we have our range, that is from 0 to to bar 16. And so that we do not pass the, We do not create any segmentation fault, trying to store a larger value in the, in an integer placeholder. We will have a long, long kind of thing, right?

        long long left = 0, right = 1;
        for(int i = 0; i < 16; i++) {
            right *= 2;
        }

        int sqrt;

        while(left <= right) {
            long long mid = ((right - left) / 2) + left;

            long long midSquare = mid * mid;
            if(midSquare <= x) {
                sqrt = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return sqrt;
    }
};