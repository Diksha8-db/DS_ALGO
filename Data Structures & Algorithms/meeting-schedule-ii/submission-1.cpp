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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> interval;
        for(int i = 0; i < intervals.size(); i++){
            interval.push_back({intervals[i].start,1});
            interval.push_back({intervals[i].end,-1});
        }

        // 2. Sort the interval array
        sort(interval.begin(), interval.end());

        // 3. Find the max overlaps
        int overlap = 0;
        int maxOverlap = INT_MIN;
        for(int i = 0; i < interval.size(); i++){
            overlap += interval[i].second;
            maxOverlap = max(maxOverlap,overlap);
        }

        return (maxOverlap == INT_MIN) ? 0 : maxOverlap;
    }
};
