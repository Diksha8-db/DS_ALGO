class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        dp[n-1] = cost[n-1]; // the maximum contributing index value
        for(int i = n-2; i >= 0; i--){
            int oneStep = cost[i] + dp[i+1];
            int twoStep = cost[i] + ((i+2 >= n) ? 0 : dp[i+2]);

            dp[i] = min(oneStep,twoStep);
        }

        return min(dp[0],dp[1]);
    }
};
