class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAr = INT_MIN;
        int n = heights.size();

        int i = 0, j = n-1;
        while(i < j){
            maxAr = max(maxAr,min(heights[i],heights[j])*(j-i)); 
            if(heights[i] > heights[j]){
                j--;
            }
            else i++;
        }

        return maxAr;
    }
};
