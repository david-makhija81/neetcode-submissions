bool comp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // So, we have to partition a given string into a number of strings, such that each letter in that string occurs in only one of those labels.
        // Each partition must be a contiguous selection of characters from the string.

        // The straightforward approach to this, would be to try all partitions of the given string and return the ones that meet the passing conditions.
        // One other way to put this statement is to partition the string in such a way that the occurrences of all the elements in one partition occur before the ending of this partition and they occur after the starting of this partition.
        // That means that the first occurence of a character of that partition must be placed after the starting of that partition and the last occurence of a character of that partition must be placed before the ending of that partition.
        // Let's say we have the string "abba" and from this string we can clearly observe watching the first and last occurence that the character 'a' exists in the range {0, 3} and the character b exists in the interval {1, 2} as a needs to exist in just one partition, thus there must not exist any partition between 0, 3
        // Let's say we have another example "abab" in this example the character 'a' exists in the range {0, 2} thus there can not be a partition between 0 & 2 and there must not be partion between 1 & 3 also thus leaving room only for partitions before 0 or after 3.
        // So, it is clear that if we represented each character by the interval in which they exist then 2 characters whose intervals overlap with each other can not exist in different partitions.
        // Thus, we must make all such intervals and mege the overlapping ones in order to find partition lengths.

        vector<int> startPos(26, -1);
        vector<int> endPos(26, -1);

        for(int i = 0; i < s.size(); i++) {
            endPos[s[i] - 'a'] = i;
            startPos[s[s.size() - i - 1] - 'a'] = s.size() - i - 1;
        }

        vector<vector<int>> intervals;

        for(int i = 0; i < 26; i++) {
            if(startPos[i] >= 0) {
                intervals.push_back({startPos[i], endPos[i]});
            }
        }

        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> mergedIntervals;

        for(auto interval: intervals) {
            if((!mergedIntervals.empty()) && (mergedIntervals.back()[1] >= interval[0])) {
                vector<int> newInterval = mergedIntervals.back();

                mergedIntervals.pop_back();

                interval = {newInterval[0], max(newInterval[1], interval[1])};
            }

            mergedIntervals.push_back(interval);
        }

        vector<int> ans;

        for(auto interval: mergedIntervals) {
            ans.push_back(interval[1] - interval[0] + 1);
        }

        return ans;
    }
};