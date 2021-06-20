class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};

// push efficient
//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}


//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
        if(q1.empty() and q2.empty()){
            return -1;
        }
        
        while(!q1.empty() and q1.size()!=1){
            int val=q1.front();
            q1.pop();
            q2.push(val);
        }
        
        int topele=q1.front();
        q1.pop();
        
        while(!q2.empty()){
            int val=q2.front();
            q2.pop();
            q1.push(val);
        }
        return topele;
        
}

//Function to pop an element from stack using two queues. 
int QueueStack :: top()
{
        // Your Code  
        if(q1.empty() and q2.empty()){
            return -1;
        }
        
        while(!q1.empty() and q1.size()!=1){
            int val=q1.front();
            q1.pop();
            q2.push(val);
        }
        
        int topele=q1.front();
        q1.push(topele);
        
        while(!q2.empty()){
            int val=q2.front();
            q2.pop();
            q1.push(val);
        }
        return topele;
        
}
