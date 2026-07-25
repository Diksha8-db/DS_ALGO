class Solution {
public:
    int profitEarned(int idx, bool canSell,vector<int>& prices,vector<vector<int>>& dp){
        // base case
        if(idx >= prices.size()) return 0;
        if(dp[idx][canSell] != -1) return dp[idx][canSell];

        if(canSell){
            // skip + not skip
            return dp[idx][canSell] = max(prices[idx] + profitEarned(idx+2,0,prices,dp), profitEarned(idx+1,1,prices,dp));
        }
        else{
            // buy or not buy
            return dp[idx][canSell] = max(-prices[idx] + profitEarned(idx+1,1,prices,dp), profitEarned(idx+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        // on first day to we have only one option to buy
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));

        dp[prices.size()][0] = 0, dp[prices.size()][1] = 0;

        for(int i = prices.size()-1; i >= 0; i--){
            // idx + can't sell
            dp[i][0] = max(-prices[i]+dp[i+1][1],dp[i+1][0]);

            // idx + can sell
            dp[i][1] = max(prices[i]+((i+2 > prices.size()) ? 0 : dp[i+2][0]), dp[i+1][1]);
        }
        // return profitEarned(0,0,prices,dp);
        return dp[0][0]; // can buy on first idx
    }
};
