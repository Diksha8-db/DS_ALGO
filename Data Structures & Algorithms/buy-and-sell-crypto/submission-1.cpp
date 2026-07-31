class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // APPROACH 1 : T.C = O(n) and S.C = O(n)
        /* 

        // tracks the max price from index i to n-1
        vector<int> maxPrice(n,0);

        maxPrice[n-1] = prices[n-1];
        for(int i = n-2; i >= 0; i--){
            maxPrice[i] = max(maxPrice[i+1],prices[i]);
        }

        int ans = 0; // max profit if no profit is gained
        for(int i = 0; i < n; i++){
            ans = max(ans,maxPrice[i] - prices[i]);
        }

        return ans;
        */

        // APPROACH 2 : 
        int maxPr = 0;
        int minVal = prices[0];

        for(int i = 0; i < n; i++){
            // if we sell on this day
            maxPr = max(maxPr, prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }

        return maxPr;
    }
};
