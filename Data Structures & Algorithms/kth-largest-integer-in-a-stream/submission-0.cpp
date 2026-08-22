class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> pq;
    int maxValidSize;
    KthLargest(int k, vector<int>& nums) {
        maxValidSize = k;
        for(int num : nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > maxValidSize)
            pq.pop();
        
        return pq.top();
    }
};
