bool comp(vector<int>& interval1, vector<int>& interval2) {
    return interval1[0] < interval2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // So I need to merge all the overlapping intervals and return a list non-overlapping intervals?
        // Are the intervals sorted among themselves in any fashion?
        // What's the condition for overlapping?

        // If the intervals were sorted according to their start point, it would have been easy to identify any overlapping intervals and merge them right there.
        // Thus, first we will sort the intervals in order with their start point.
        // We keep an answer of non-overlapping intervals, we'll insert intervals out of the actual input into this one.
        // When inserting an interval we check if this interval overlaps with the last inserted interval in the answer - if they do overlap then we'll merge the last inserted interval and the current interval else we insert the current interval itself.

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), comp);

        for(auto interval: intervals) {
            if((!ans.empty()) && (ans.back()[1] >= interval[0])) {
                vector<int> prevInterval = ans.back();
                ans.pop_back();

                ans.push_back({prevInterval[0], max(prevInterval[1], interval[1])});
            } else {
                ans.push_back(interval);
            }
        }

        return ans;
    }
};