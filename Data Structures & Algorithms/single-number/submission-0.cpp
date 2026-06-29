class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int num : nums){
            ans ^= num; // num^num = 0 so the answer will contain the element with single occurance
        }
        return ans;
    }
};
