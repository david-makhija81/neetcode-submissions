class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // So, we need some gas to go from one station to the successive one and we get some at that station as well do we reserve the unused fuel when we go from one station to another?

        // So, the straightforward approach would be to try starting from each gas station to find the one which can complete the circuit.
        // But this would take a lot of time, let's try to find the solution in lesser time
        // In my view it we need to have the most of fuel reserves as we go through the gas stations, but how do we determine the station starting from where we would have the most fuel reserves.
        // Also to determine if we cannot complete the circuit we should sum the costs and gas values if the costs are greater than the gas combined then there's no way we can bear the travelling costs.
        // So, now we know that there does exist a solution but we do not know where, so we try starting from the 0th index we travel along towards the end of the array we keep track of the gas in our tank if at any point it becomes negative then that means if we start at any index before this one then we would not be able to complete the circuit and then we reset our starting position until the last index we stop there because we know that there does exist a solution

        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int start = 0;
        int tank = 0;

        for(int i = 0; i < gas.size(); i++) {
            tank += (gas[i] - cost[i]);

            if(tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return start;
    }
};