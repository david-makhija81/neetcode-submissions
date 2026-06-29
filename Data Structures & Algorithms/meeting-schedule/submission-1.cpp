/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

bool comparator(Interval& interval1, Interval& interval2) {
    return interval1.start < interval2.start;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start == intervals[i - 1].start) {
                return false;
            }

            if(intervals[i - 1].end > intervals[i].start) {
                return false;
            }
        }

        return true;
    }
};
