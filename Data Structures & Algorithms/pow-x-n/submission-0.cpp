class Solution {
public:
    double myPow(double x, int n) {
        // The simplest or standard mathematical algorithms advice us to multiply x to product about n times, but that would take a lot of operations and would not fit in our time limit.
        // On another note if I have to calculate (x to the power n) and n is divisible by 2 it makes sense to calculate (x to the power (n / 2)) and just return the square of it. This way we can reduce the number of operations to a logarithmic order.

        if(n == 0) {
            return 1;
        }

        if(n < 0) {
            return (1 / (x * myPow(x, abs(n + 1))));
        }

        if((n % 2) == 1) {
            return (x * myPow(x, n - 1));
        }

        double sqrt = myPow(x, n/2);

        double ans = (sqrt * sqrt);

        return ans;
    }
};