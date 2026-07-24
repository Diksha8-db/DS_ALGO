class Solution {
public:
    int calcLen(vector<int>& nums, int prevIdx, int idx,vector<vector<int>>& dp){
        // base case
        if(idx == nums.size()){
            return 0;
        }

        if(dp[prevIdx+1][idx] != -1) return dp[prevIdx+1][idx];

        int notPick = calcLen(nums,prevIdx,idx+1,dp);
        int pick = 0;

        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            pick = 1 + calcLen(nums,idx,idx+1,dp);
        }

        return dp[prevIdx+1][idx] = max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;

        vector<int> dp(n,1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            maxLength = max(maxLength,dp[i]);
        }
        return maxLength;
    }
};
