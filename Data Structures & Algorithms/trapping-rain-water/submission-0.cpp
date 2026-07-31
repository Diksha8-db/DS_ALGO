class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);

        // calculate the left max
        leftMax[0] = heights[0];
        rightMax[n-1] = heights[n-1];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1],heights[i]);
        }

        // calculate the right max
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1],heights[i]);
        
        int res = 0;
        for(int i = 0; i < n; i++){
            res += min(leftMax[i],rightMax[i]) - heights[i];
        }
        return res;
    }
};
