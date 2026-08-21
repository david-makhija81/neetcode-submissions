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

bool comp(Interval& interval1, Interval& interval2) {
    return (interval1.start < interval2.start);
}

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // Are the meeting schedules sorted in any order?
        // Are the meetings [0, 5] and [5, 7] considered to be in conflict?

        // So, we have to recognize the conflicts in meeting schedules and assign an additional meeting room, if there is a conflict in 2 meetings.
        // We have to find the minimum number of meeting rooms that would do the job.
        // Let's say we have intervals like [[0, 5], [3, 6], [5, 7]]
        // In this case the first meeting has a conflict with the second one and the second one has a conflict with the 3rd one, if we only counted the number of intervals in conflict we would naively return 3 meeting rooms.
        // But, one can easily figure out that we can make these meetings happen in only 2 rooms without a single conflict - 1st and 3rd meeting in one room and the 2nd meeting in another one.
        // So, if the meetings are sorted in order of there starting times - Via this we already know which meeting room has already occupied the room while the other is waiting to start.
        // This conflict is determined by the ending time of the last meeting in that meeting room.
        // Thus, we can be greedy and make a list of meeting rooms which keeps the chances of conflict minimum (i.e. least ending time) up above in the list.
        // Every time we need to insert a meeting we just push it to the meeting room with least ending time if it still has a conflict with that room then we make another room for that meeting and update that meeting room's end time.

        priority_queue<int, vector<int>, greater<int>> meetingRooms;

        sort(intervals.begin(), intervals.end(), comp);

        for(auto interval: intervals) {
            if((!meetingRooms.empty()) && (interval.start >= meetingRooms.top())) {
                meetingRooms.pop();
                meetingRooms.push(interval.end);
            } else {
                meetingRooms.push(interval.end);
            }
        }

        return meetingRooms.size();
    }
};
