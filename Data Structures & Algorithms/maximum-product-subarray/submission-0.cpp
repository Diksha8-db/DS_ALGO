class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int res = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int temp = max({nums[i],nums[i]*maxProd,nums[i]*minProd});
            minProd = min({nums[i],nums[i]*maxProd,nums[i]*minProd});
            maxProd = temp;
            res = max(res,maxProd);
        }

        return res;
    }
};
