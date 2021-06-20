class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1; // for storing all the elements
    stack<int> s2;
    MinStack() {
    }

    void push(int x) {
        // push in s2 only if value is smaller than the top value of s2 or is empty (for first entry)
        if(s2.empty() or x<=s2.top()){
            s2.push(x);
        }
        // always push in s1
        s1.push(x);
    }
    
    void pop() {
        // pop only if both top data is same
         if(s1.top()==s2.top()){
                s2.pop();
          }
        //  always pop from s1
        s1.pop();
    }
    
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};