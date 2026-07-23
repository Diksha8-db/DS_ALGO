class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int notPick = 0;
        int pick = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            int temp_pick = nums[i] + notPick;
            int temp_no_pick = pick;
            int temp = max(temp_pick,temp_no_pick);
            notPick = pick;
            pick = temp;
        }   

        return max(pick,notPick);
    }
};
