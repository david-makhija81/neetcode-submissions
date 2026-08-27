class Solution {
public:
    int reverse(int x) {
        // I suppose reversing an integer means mmaking the most significant digit the least significant and vice-versa thus we'll go by that approach only.

        int ans = 0;

        while(x != 0) {
            int leastSigDigit = (x % 10);
            x /= 10;

            if((ans > (INT_MAX / 10)) || ((ans == (INT_MAX / 10)) && (leastSigDigit > (INT_MAX % 10)))) {
                return 0;
            }
            if((ans < (INT_MIN / 10)) || ((ans == (INT_MIN / 10)) && (leastSigDigit < (INT_MIN % 10)))) {
                return 0;
            }

            ans = (10 * ans) + leastSigDigit;
        }

        return ans;
    }
};