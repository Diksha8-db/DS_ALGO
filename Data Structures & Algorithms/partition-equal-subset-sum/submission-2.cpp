class Solution {
public:
    bool canDivide(int totalSum, int idx, vector<int>& nums){
        if(totalSum == 0) return true;
        if(idx < 0 || totalSum < 0) return false; // can't be partitioned more 

        bool include;
        if(nums[idx] <= totalSum){
            include = canDivide(totalSum-nums[idx],idx-1,nums);
        }
        bool exclude = canDivide(totalSum,idx-1,nums);

        return (exclude || include);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int num : nums)
            totalSum += num;
        
        vector<bool> dp(totalSum/2+1,0);
        
        // if the sum is odd-> can't be partitioned
        if(totalSum % 2 != 0) return false;
        else{
            // if sum is even -> can be partitioned or not
            // return canDivide(totalSum/2,n-1,nums);

            // tabulation
            dp[0] = true;

            for(int i = 0; i < n; i++){
                for(int j = totalSum/2; j >= 0; j--){
                    if(j-nums[i] >= 0 && dp[j-nums[i]]){
                        dp[j] = true;
                    }
                }
            }
        }
        return dp[totalSum/2];
    }
};
