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
        n = nums.size();
        // dp.resize(200001,vector<int>(n,-1));

        return findWays(nums,target,0);
    }
};
