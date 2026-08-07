class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
    }
    
    void push(int val) {
        // push the value in the stack along with the minval till date
        if(!st.empty()){
            int minVal = st.top().second;
            st.push({val,min(minVal,val)});
        }
        else st.push({val,val});
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        int val = st.top().first;
        return val;
    }
    
    int getMin() {
        int minVal = st.top().second;
        return minVal;
    }
};
