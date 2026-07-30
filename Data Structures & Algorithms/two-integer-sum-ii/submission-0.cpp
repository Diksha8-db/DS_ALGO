class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // APPROACH 1: Brute Force O(n^2)
        int n = numbers.size();
        /*
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(numbers[i] + numbers[j] == target){
                    return {i+1,j+1};
                }
            }
        }
        */

        // APPROACH 2 : Better Approach O(nlogn)
        /*
        for(int i = 0; i < n; i++){
            int otherNum = target-numbers[i];
            int left = 0, right = n-1;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(numbers[mid] == otherNum){
                    return {i+1,mid+1};
                }

                else if(numbers[mid] > otherNum){
                    // number is present in the left half
                    right = mid-1;
                }
                else left = mid+1; // number is present in the right half
            }
        }
        */

        // APPROACH 3 : BEST APPROACH (2-Pointers)
        int i = 0, j = n-1;
        while(i <= j){
            if(numbers[i] + numbers[j] == target){
                return {i+1,j+1};
            }
            else if(numbers[i]+numbers[j] > target){
                j--;
            }
            else i++;
        }
    }
};
