class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // BRUTE FORCE :
        // 1. for each query traverse whole interval in intervals array and return the one with min Length : T.C = O(intervals.size()*queries.size())

        /*
        int n = intervals.size();
        int m = queries.size();
        vector<int> output;

        for(int i = 0; i < m; i++){
            int minLen = INT_MAX;
            for(int j = 0; j < n; j++){
                if(queries[i] >= intervals[j][0] && queries[i] <= intervals[j][1]){
                    minLen = min(minLen,(intervals[j][1]-intervals[j][0]+1));
                }
            }
            if(minLen != INT_MAX) output.push_back(minLen);
            else output.push_back(-1);
        }

        return output;
        */

        // OPTIMISED VERSION :
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
    
        // Sort queries by their value, and sort intervals by their start points
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(intervals.begin(), intervals.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
        vector<int> ans(queries.size());
        int idx = 0; // Pointer for intervals

        // Iterate through the sorted queries
        for (int i = 0; i < sortedQueries.size(); i++) {
            int qVal = sortedQueries[i].first;
            int qIdx = sortedQueries[i].second;

            // 1. Add all intervals that START before or at the current query value
            while (idx < intervals.size() && intervals[idx][0] <= qVal) {
                int left = intervals[idx][0];
                int right = intervals[idx][1];
                minHeap.push({right - left + 1, right});
                idx++;
            }

            while (!minHeap.empty() && minHeap.top().second < qVal) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                ans[qIdx] = minHeap.top().first;
            } else {
                ans[qIdx] = -1;
            }
        }
    return ans;
    }
};