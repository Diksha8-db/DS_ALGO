class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 1. Sort the array
        sort(intervals.begin(), intervals.end());

        int prevEnd = intervals[0][1];
        int count = 0;

        for(int i = 1; i < intervals.size(); i++){
            if(prevEnd > intervals[i][0]){
                prevEnd = min(prevEnd,intervals[i][1]);
                count++;
            }
            else prevEnd = intervals[i][1];
        }
        return count;
    }
};
