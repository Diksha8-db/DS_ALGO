class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        // APPROACH 1 : BRUTE FORCE O(n^3)
        /*
        int n = nums.size();
        set<vector<int>> ans;
        for(int i = 0;i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1;k < n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> res;
        for(vector<int> v : ans){
            res.push_back(v);
        }

        return res;
        */

        // BSET APPROACH 
        // nums[i] + nums[j] = -nums[k]
        sort(nums.begin(),nums.end()); // O(nlogn)

        for(int i = 0; i < n; i++){
            int target = -nums[i]; // fixing the target
            int left = 0, right = n-1;

            while(left < right){
                if(nums[left] + nums[right] == target){
                    if(i != left && i != right){
                        vector<int> temp = {nums[i],nums[left],nums[right]};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] > target) right--;
                else left++;
            }
        }

        vector<vector<int>> res;
        for(vector<int> v : ans){
            res.push_back(v);
        }

        return res;
    }
};
