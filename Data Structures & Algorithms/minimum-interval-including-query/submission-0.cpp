bool sortComp(vector<int>& a, vector<int>& b) {
    return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
}

struct pqComp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return (a[0] > b[0]) || ((a[0] == b[0]) && (a[1] > b[1]));
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // So, two intervals collide when interval1[0] <= interval2[1] and interaval1[0] >= interval2[0]
        
        // So, I have to find for each query the smallest interval which this query is a part of.
        // The straightforward solution to this, would be to examine all the intervals that contain this query and compare all their lengths.
        // But this would take a lot of time, let's try to find a solution with lesser time complexity.
        // The general flow/approach stays the same where first we find all the appropriate intervals for a query and then compare their sizes.
        // We just need to optimize the interval lookups and mutual comparisons.
        // So, if we arranged the intervals in a sorted order of their starting times and also sorted queries then it would be easier to traverse through both of them at the same time and figure out if the query is included in the current interval or not.

        sort(intervals.begin(), intervals.end(), sortComp);
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<vector<int>, vector<vector<int>>, pqComp> recentInterval;
        unordered_map<int, int> queryIntervalLength;

        int idx = 0;
        for(int query: sortedQueries) {
            while((idx < intervals.size()) && (intervals[idx][0] <= query)) {
                int left = intervals[idx][0], right = intervals[idx][1];
                recentInterval.push({right - left + 1, right});
                idx++;
            }

            while((!recentInterval.empty()) && (recentInterval.top()[1] < query)) {
                recentInterval.pop();
            }

            if(recentInterval.empty()) {
                queryIntervalLength[query] = -1;
            } else {
                queryIntervalLength[query] = recentInterval.top()[0];
            }
        }

        vector<int> ans;

        for(int query: queries) {
            ans.push_back(queryIntervalLength[query]);
        }

        return ans;
    }
};