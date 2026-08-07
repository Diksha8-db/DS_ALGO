class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmaller(n), prevSmaller(n);
        
        // 1. Next Smaller Element
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // 2. Previous Smaller Element
        stack<int> st2; // Use st2 here
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && heights[st2.top()] >= heights[i]) {
                st2.pop();
            }
            prevSmaller[i] = st2.empty() ? -1 : st2.top();
            st2.push(i);
        }

        // 3. Calculate Maximum Area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};