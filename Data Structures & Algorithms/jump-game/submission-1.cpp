class Solution {
public:
    vector<int> dp;
    bool canReach(int i, vector<int>& nums){
        // base case
        if(i >= nums.size()) return 0;
        if(i == nums.size() - 1){
            return 1;
        }
        if(dp[i] != -1) return dp[i];

        bool ans = false;
        for(int posVal = 1; posVal <= nums[i]; posVal++){
            ans = ans | (canReach(i+posVal,nums));
        }
        return dp[i] = ans;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return (canReach(0,nums) == 1) ? true: false;
    }
};
