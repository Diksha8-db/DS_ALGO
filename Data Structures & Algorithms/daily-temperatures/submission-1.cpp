class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);

        stack<int> st; // to store the next greater element index
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            
            if(st.empty())
                result[i] = 0;
            else result[i] = st.top() - i;

            st.push(i);
        }

        return result;
    }
};
