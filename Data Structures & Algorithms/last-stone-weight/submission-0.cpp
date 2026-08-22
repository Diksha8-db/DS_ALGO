class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // maxHeap
        for(int stone : stones)
            pq.push(stone);
        
        while(!pq.empty() && pq.size() != 1){
            int op1 = pq.top();
            pq.pop();
            int op2 = pq.top();
            pq.pop();

            if(op1 == op2) continue;
            else pq.push(abs(op1-op2));
        }

        return ((pq.empty()) ? 0 : pq.top());
    }
};
