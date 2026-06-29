class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // k and top k freq -> minHeap can be thought of T.C = O(n + k*logk) and S.C = O(n)

        unordered_map<int,int> freqMap;
        for(int num : nums){
            freqMap[num]++;
        }

        // iterate through the map and store the k elements in minHeap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto const&[val,freq] : freqMap){
            pq.push({freq,val});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
