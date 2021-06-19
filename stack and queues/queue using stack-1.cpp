class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; 

void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop(){
      
        if(s2.empty()){
            while(!s1.empty()){
                int val=s1.top();
                s1.pop();
                s2.push(val);
            }
        }
      
        int x=s2.top();
        s2.pop();
        return x;        
}

