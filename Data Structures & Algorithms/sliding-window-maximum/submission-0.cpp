class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        // we need to find the maximum element in less time for every window
        // data structure that will help out -> priority queue along with index tag
        priority_queue<pair<int,int>> pq;
        int n = nums.size();

        int i = 0,j=0;
        // insert the first window
        for(j = 0; j < k; j++){
            pq.push({nums[j],j});
        }

        ans.push_back(pq.top().first);

        for(j = k; j < n; j++){
            // insert the current element
            pq.push({nums[j],j});

            // remove the top if the index is out of bound
            while(!pq.empty() && pq.top().second <= j-k){
                pq.pop();
            }
        
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
