class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // APPROACH 1 : use a freq map to store the frequency of each element
        // T.C = O(n) and S.C = O(n)
        /*
        unordered_map<int,int> freqMap;
        for(int num : nums){
            freqMap[num]++;
            if(freqMap[num] > 1) return num;
        }
        */

        // APPROACH 2
        for(int i = 0; i < nums.size(); i++){
            int targetIdx = abs(nums[i]);
            if(nums[targetIdx] < 0) return targetIdx;
            
            nums[targetIdx] = -nums[targetIdx];
        }
        return -1;
    }
};
