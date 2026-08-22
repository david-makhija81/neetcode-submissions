class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // For each day, I need to figure out for how many days I must wait in order to get a warmer temperature?
        // The straightforward approach for this, would be to linearly check ahead of this day what temperature is warmer than this one and then repeat it for every day.
        // But, there is a shortcut to this approach - For example, we can store the warmest days in structure in future and update it as we go along the days, from right to left (future to the past).
        // And when we have to look for a warmer day in the future - we just look at the closest warmest day and if that day does not have a warmer temperature than this one then we delete this warmest day from the structure because we already have a warmer day than this one in the past that is the current day and thus, we look at further more temperatures in the future and repeat this process.

        stack<int> mostRecentWarmerTemp;

        vector<int> ans(temperatures.size(), 0);

        for(int i = temperatures.size() - 1; i >= 0; i--) {
            while(
                (!mostRecentWarmerTemp.empty()) && 
                (temperatures[mostRecentWarmerTemp.top()] <= temperatures[i])
            ) {
                mostRecentWarmerTemp.pop();
            }

            if(!mostRecentWarmerTemp.empty()) {
                ans[i] = mostRecentWarmerTemp.top() - i;
            }

            mostRecentWarmerTemp.push(i);
        }

        return ans;
    }
};