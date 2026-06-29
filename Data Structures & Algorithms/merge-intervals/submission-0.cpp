bool comparator(vector<int>& interval1, vector<int>& interval2) {
    return (interval1[0] < interval2[0]);
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            if(result.back()[1] >= intervals[i][0]) {
                vector<int> lastInterval = result.back();
                result.pop_back();

                result.push_back({min(intervals[i][0], lastInterval[0]), max(intervals[i][1], lastInterval[1])});
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};