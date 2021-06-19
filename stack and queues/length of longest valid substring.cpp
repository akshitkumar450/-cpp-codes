   int longestValidParentheses(string str) {
             stack<int>st; // store the index of brackets
        int len=0;
        st.push(-1);
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                st.push(i);
            } else{
                // Pop the previous opening
            // bracket's index
                 st.pop();
                if(!st.empty()){
                     
            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
                    len=max(len,i-st.top());
                } else{
                    // If stack is empty. push current index as
            // base for next valid substring (if any)
                    st.push(i);
                }
            }
        }
        return len;
    }