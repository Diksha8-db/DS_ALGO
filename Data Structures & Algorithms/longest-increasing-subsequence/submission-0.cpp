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
        int maxLength = INT_MIN;

        vector<vector<int>> dp(2001,vector<int>(n,-1));

        maxLength = max(maxLength, calcLen(nums,-1,0,dp));
        

        return maxLength;
    }
};
