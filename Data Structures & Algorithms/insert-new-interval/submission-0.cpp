class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Are the intervals overlapping?
        // Are the intervals sorted?
        // What intervals are exactly overlapping: are these overlapping [1, 2] & [2, 3]?

        // As the intervals are non-overlapping, we can imagine them as sessions where one happens after another.
        // And, the start of next session in sequence is greater than that of the end of this one.
        // If we insert an interval into a sequence like this the interval may lead to an overlap between a lot of intervals
        // For example, [[1, 5], [9, 16], [20, 23]] and the interval to be inserted is [4, 20] then the answer sequence might look something like [[1, 23]].
        // So, we will maintain an answer where we push the array's intervals themselves along with the interval to be inserted.
        // As we know that after insertion the array should remain sorted thus for each interval in the array we must compare it's start with the start of interval to be inserted - this helps us figure out the exact position where the interval to be inserted belongs.
        // After figuring out what to insert we check if the interval we have chosen overlaps with the last pushed interval - if they do overlap then we merge these 2 intervals else we insert them as it is.
        
        vector<vector<int>> ans;
        bool newIntervalInserted = false; // This boolean tracks if the newInterval has yet been inserted or not.
        int i = 0;

        while(i < intervals.size()) {
            if((!newIntervalInserted) && (newInterval[0] < intervals[i][0])) {
                if((!ans.empty()) && (ans.back()[1] >= newInterval[0])) {
                    vector<int> prevInterval = ans.back();
                    ans.pop_back();

                    ans.push_back({prevInterval[0], max(prevInterval[1], newInterval[1])});

                    // cout << "Inserted the interval: [" << ans.back()[0] << ", " << ans.back()[1] << "]" << endl;
                } else {
                    ans.push_back(newInterval);
                    // cout << "Inserted the interval: [" << ans.back()[0] << ", " << ans.back()[1] << "]" << endl;
                }

                newIntervalInserted = true;
            } else {
                if((!ans.empty()) && (ans.back()[1] >= intervals[i][0])) {
                    vector<int> prevInterval = ans.back();
                    ans.pop_back();

                    ans.push_back({prevInterval[0], max(prevInterval[1], intervals[i][1])});
                    // cout << "Inserted the interval: [" << ans.back()[0] << ", " << ans.back()[1] << "]" << endl;
                } else {
                    ans.push_back(intervals[i]);
                    // cout << "Inserted the interval: [" << ans.back()[0] << ", " << ans.back()[1] << "]" << endl;
                }

                i++;
            }

            // cout << "idx: " << i << endl;
        }

        if(!newIntervalInserted) {
            if((!ans.empty()) && (ans.back()[1] >= newInterval[0])) {
                vector<int> prevInterval = ans.back();
                ans.pop_back();

                ans.push_back({prevInterval[0], max(prevInterval[1], newInterval[1])});

                // cout << "Inserted the interval: [" << ans.back()[0] << ", " << ans.back()[1] << "]" << endl;
            } else {
                ans.push_back(newInterval);
                // cout << "Inserted the interval: [" << ans.back()[0] << ", " << ans.back()[1] << "]" << endl;
            }
        }

        return ans;
    }
};