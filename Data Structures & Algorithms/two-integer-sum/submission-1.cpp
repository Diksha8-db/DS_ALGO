class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> indexMap; // nums[i] and index

        for(int i = 0; i < n; i++){
            indexMap[nums[i]] = i;
        }

        for(int i = 0; i < n; i++){
            if(indexMap.count(target-nums[i])){
                int j = indexMap[target-nums[i]];
                if(i != j) return {i,j};
            }
        }

        return {-1,-1};
    }
};
