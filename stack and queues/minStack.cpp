class MinStack {
public:
    stack<int> s1; // for storing all the elements
    stack<int> s2; // for storing min element at any point of time
    MinStack() {}

    void push(int x) {
        // we will push every element in s1 
        // but in s2 we will push only when the current element is smaller than the top of s2
        // we will also store if there are same smaller elements in s2
        // if s1 is empty means it the first element then we will push in both
        // bcz single element is also min 
        if (s1.empty() or x <= s2.top()) {
            s1.push(x);
            s2.push(x);
        } else {
            s1.push(x);
        }
    }

    void pop() {
        // if top of both stacks are same,means that element is min till now
        if (s1.top() == s2.top()) {
            s1.pop();
            s2.pop();
        } else {
            s1.pop();
        }
    }

    // to get the top value
    int top() {
        return s1.top();
    }

    // to get the minimum at any point
    int getMin() {
        return s2.top();
    }
};