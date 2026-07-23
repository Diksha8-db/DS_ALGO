class Solution {
public:
    int findMaxVal(int i, int j, vector<int> nums){
        int notPick = 0;
        int pick = 0;

        for(int k = j; k >= i; k--){
            int temp  = max(nums[k] + notPick,pick);
            notPick = pick;
            pick = temp;
        }
        return max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n == 1) return nums[0];
        
        return max(findMaxVal(0,n-2,nums), findMaxVal(1,n-1,nums));
    }
};
