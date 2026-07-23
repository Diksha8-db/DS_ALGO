class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1);
        dp[n] = 0;
        dp[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            int pick = nums[i] + ((i+2 >= n) ? 0 : dp[i+2]);
            int notPick = dp[i+1];
            dp[i] =  max(pick,notPick);
        }   

        return dp[0];
    }
};
