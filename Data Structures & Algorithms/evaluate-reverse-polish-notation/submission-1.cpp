class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int n = tokens.size();
        // push the values in the stack
        for(int i = 0; i < n; i++){
            string ch = tokens[i];
            // if it is any operand then evaluate the val and push it onto the stack
            if(ch == "+" || ch == "/" || ch == "*" || ch == "-"){
                // take out teh first and secong operands
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if(ch == "+") st.push(op1+op2);
                else if(ch == "-") st.push(op1-op2);
                else if(ch == "*") st.push(op1*op2);
                else st.push(op1/op2);
            }
            else{
                // if the number is integer push it on to the stack
                int val = stoi(ch);
                st.push(val);
            }
        }

        return st.top();
    }
};
