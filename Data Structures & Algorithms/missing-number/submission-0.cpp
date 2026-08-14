class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // find the xor value from 0 to n
        int n = nums.size();
        int xorVal = 0;

        for(int i = 0; i <= n; i++)
            xorVal ^= i;

        // now 1^1 = 0, 2^2 = 0 : using this property to find the missing element
        for(int num : nums)
            xorVal ^= num;
        
        return xorVal;
    }
};
