class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int findWays(vector<int>& nums, int sum, int idx){
        // base case
        if(idx == n && sum == 0) return 1; // found a way 
        else if(idx == n && sum != 0) return 0; // no path exist

        int count = 0;
        // take negative
        count += findWays(nums,sum - nums[idx],idx+1);

        // take positive
        count += findWays(nums,sum+nums[idx],idx+1);
        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if((totalSum + target) % 2!= 0 || totalSum < abs(target)) return 0;
        int t = (totalSum + target) / 2; // subset sum we need

        vector<vector<int>> dp(t + 1, vector<int>(n + 1, 0));

        // Base: 1 way to make sum 0 with any number of elements
        for(int j = 0; j <= n; j++){
            dp[0][j] = 1;
        }

        for(int j = 1; j <= n; j++){ // use first j elements
            for(int i = 0; i <= t; i++){ // make sum i
                int skip = dp[i][j - 1]; // don't take nums[j-1]
                int take = 0;
                if(i >= nums[j - 1]){ // take nums[j-1]
                    take = dp[i - nums[j - 1]][j - 1];
                }
                dp[i][j] = skip + take;
            }
        }
        return dp[t][n];
    }
};
