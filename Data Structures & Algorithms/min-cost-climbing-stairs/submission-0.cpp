class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // The straightforward approach for this problem would be to just explore all the paths and return the minimum cost out of all of them.
        // But that approach would consume a lot of operations.
        // And while discovering all the paths the sub paths that make up these paths might even repeat.
        // Thus we'll try to leverage some efficiency by using these sub paths.
        // We'll start from an elementary number of stairs and we'll keep calculating the answers to further problems until we have the solution to the actual problem.

        vector<int> minCostTillThisStep(cost.size(), 0);

        minCostTillThisStep[0] = cost[0];
        minCostTillThisStep[1] = cost[1];

        for(int i = 2; i < cost.size(); i++) {
            minCostTillThisStep[i] = min(
                minCostTillThisStep[i - 1],
                minCostTillThisStep[i - 2]
            ) + cost[i];
        }

        return min(
            minCostTillThisStep[cost.size() - 1],
            minCostTillThisStep[cost.size() - 2]
        );
    }
};