bool comp(vector<int>& interval1, vector<int>& interval2) {
    return (interval1[0] < interval2[0]);
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // So, I need to return the minimum number of intervals I need delete in order to make the entire sequence non-overlapping?
        // Let's take an example [[1, 4], [3, 10], [5, 6], [7, 8]] in this example, the minimum number of intervals to be deleted to make the array of intervals non-overlapping.
        // In the given case as we go through the intervals from left to right and we encounter a clash between the first and second interval in this clash how do we decide which interval we delete - keeping in mind we have to minimize the number of further deletions. If we delete the interval that has the minimum tendency to clash/overlap with the other intervals then we keep that one and delete the other one.
        // One way to figure out the interval that has minimum chances of over-lapping with further intervals is to choose the interval with smallest ending point.
        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> ans; // set of intervals after minimum deletions.

        for(auto interval: intervals) {
            if((!ans.empty()) && (ans.back()[1] > interval[0])) {
                vector<int> prevInterval = ans.back();
                ans.pop_back();

                ans.push_back((interval[1] < prevInterval[1]) ? interval : prevInterval);
            } else {
                ans.push_back(interval);
            }
        }

        return (intervals.size() - ans.size());
    }
};