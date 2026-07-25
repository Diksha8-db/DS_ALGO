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
        return profitEarned(0,0,prices,dp);
    }
};
