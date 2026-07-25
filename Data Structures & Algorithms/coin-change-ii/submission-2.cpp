class Solution {
public:
    vector<vector<int>> dp;
    int totalWays(int sum, vector<int>& coins, int idx){
        // base case
        if(sum == 0) return 1;
        if(idx >= coins.size() && sum != 0) return 0;
        if(dp[sum][idx] != -1) return dp[sum][idx];

        if(sum >= coins[idx]){
            return dp[sum][idx] = totalWays(sum-coins[idx],coins,idx) + totalWays(sum,coins,idx+1);
        }
        else return totalWays(sum,coins,idx+1);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(amount+1,vector<int>(n+1,-1));
        return totalWays(amount,coins,0);
    }
};
