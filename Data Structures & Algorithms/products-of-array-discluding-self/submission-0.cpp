class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // APPROACH 1 : calculate the product of the array and at every idx just divide by the index value
        int n = nums.size();
        vector<int> leftSide(nums),rightSide(nums);

        // for every index we need product of left* product of right
        for(int i = 1; i < n; i++){
            leftSide[i] = leftSide[i-1]*nums[i];
        }

        for(int i = n-2; i >= 0; i--)
            rightSide[i] = rightSide[i+1]*nums[i];
        
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = (((i-1 >= 0) ? leftSide[i-1] : 1) * ((i+1 < n) ? rightSide[i+1] : 1));
        }

        return ans;
    }
};
