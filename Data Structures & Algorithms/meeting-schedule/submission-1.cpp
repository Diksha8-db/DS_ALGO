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

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort the intervals
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            if (a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        });

        int prevEnd = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            if(prevEnd > intervals[i].start) return false;
            prevEnd = intervals[i].end;
        }

        return true;
    }
};
