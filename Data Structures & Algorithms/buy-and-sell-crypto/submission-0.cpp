class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

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
    }
};
