class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the intervals array
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> mergedIntervals;

        int idx = 1;
        mergedIntervals.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            if(mergedIntervals[idx-1][1] >= intervals[i][0]){
                // [1,5] , [2,3]
                mergedIntervals[idx-1][0] = min(mergedIntervals[idx-1][0],intervals[i][0]);
                mergedIntervals[idx-1][1] = max(mergedIntervals[idx-1][1], intervals[i][1]);
            }
            else{
                // insert the new interval and increment the idx
                mergedIntervals.push_back(intervals[i]);
                idx++;
            }
        }
        return mergedIntervals;
    }
};
