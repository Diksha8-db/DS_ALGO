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
        dp.resize(amount+1,vector<int>(n+1,0));
        // return totalWays(amount,coins,0);

        for(int i = 0; i <= n; i++)
            dp[0][i] = 1;
        
        for(int i = 1; i <= amount; i++){
            for(int j = 1; j <= n; j++){
                if(i >= coins[j-1]){
                    dp[i][j] = dp[i-coins[j-1]][j]+dp[i][j-1];
                }
                else dp[i][j] = dp[i][j-1];
            }
        }

        return dp[amount][n];
    }
};
