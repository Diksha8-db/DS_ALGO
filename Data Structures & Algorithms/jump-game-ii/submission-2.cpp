class Solution {
public:
    vector<int> dp;
    int minJump(int i, vector<int>& nums){
        // base case
        if(i >= nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];

        int minVal = 1e9;
        for(int posVal = 1; posVal <= nums[i]; posVal++){
            minVal = min(minVal,1+minJump(i+posVal,nums));
        }
        return dp[i] = minVal;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return minJump(0,nums);
    }
};
