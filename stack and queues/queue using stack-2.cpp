class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; 

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x) {
    s1.push(x);   
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop() {
        if(s1.empty() and s2.empty()){
            return -1;
        }
        
        // pop from stack 1 untill t has one element and push it to stack2
        while(!s1.empty() and s1.size()!=1){
            int val=s1.top();
            s1.pop();
            s2.push(val);
        }
        // one left element in stack 1 will be front element 
        int popped= s1.top();
        s1.pop();
        
        // copy back from stack 2 to stack 1
        while(!s2.empty()){
            int val=s2.top();
            s2.pop();
            s1.push(val);
        }
        
        return popped;
}