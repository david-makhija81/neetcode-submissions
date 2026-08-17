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

bool comp(Interval& a, Interval& b) {
    return (a.start < b.start);
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        if(intervals.size() <= 1) {
            return true; // If there is only one or no meetings at all we can easily attend all the meetings.
        }

        // If we have one meeting ending at 5 and another meeting starting at 5 say a testcase like [[4,5],[5,6]] - is there a conflict in this situation or can he attend both the meetings?
        // Are the intervals sorted in any order?

        // If I have a set of meetings, the meeting starting earliest must end before any other meetings start.
        // One pattern is clear, if it starts earlier, then it must end earlier than the next one's start time.
        // Thus I may sort the Intervals on the basis of their start time and then keep on checking if the next meeting starts after this meeting ends
        // For example if I have a schedule like [[1,2],[2,3],[4,5]] if if the first meeting ends before 2nd and the 2nd meeting ends before 3rd it is obvious that the 1st meeting would end before the 3rd one and all the meetings can take place without any clashes.
        // Thus, we only have to compare the neighbours in the sorted intervals in order to look for any clashes.

        sort(intervals.begin(), intervals.end(), comp);

        for(int i = 0; i < (intervals.size() - 1); i++) {
            if(intervals[i + 1].start < intervals[i].end) {
                return false; // Clash Detected, can not attend all meetings.
            }
        }

        return true;
    }
};
