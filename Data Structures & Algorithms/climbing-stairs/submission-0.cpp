class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }

        vector<int> distinctWaysToReachHere(n + 1, 0);

        distinctWaysToReachHere[1] = 1;
        distinctWaysToReachHere[2] = 2;

        for(int i = 3; i <= n; i++) {
            distinctWaysToReachHere[i] = distinctWaysToReachHere[i - 1] + distinctWaysToReachHere[i - 2]; 
        }

        return distinctWaysToReachHere[n];
    }
};