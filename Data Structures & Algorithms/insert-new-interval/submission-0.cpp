class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;
        int n = intervals.size();
    
        bool doneInsertion = false;
        for(int i = 1; i <= n; i++){
            if(!doneInsertion && intervals[i-1][0] > newInterval[0]){
                newIntervals.push_back(newInterval);
                doneInsertion = true;
            }
            newIntervals.push_back(intervals[i-1]);
        }

        if(!doneInsertion) newIntervals.push_back(newInterval);

        // now merge intervals
        vector<vector<int>> mergedIntervals;
        int idx = 0;
        for(int i = 0; i <= n; i++){
            if(idx == 0){
                mergedIntervals.push_back(newIntervals[i]);
                idx++;
            }
            else{
                if(mergedIntervals[idx-1][1] >= newIntervals[i][0]){
                    mergedIntervals[idx-1][0] = min(mergedIntervals[idx-1][0], newIntervals[i][0]);
                    mergedIntervals[idx-1][1] = max(mergedIntervals[idx-1][1], newIntervals[i][1]);
                }
                else{
                    mergedIntervals.push_back(newIntervals[i]);
                    idx++;
                }
            }
        }

        return mergedIntervals;
    }
};
