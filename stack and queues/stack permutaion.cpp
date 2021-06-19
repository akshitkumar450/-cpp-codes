#include <iostream>
#include <queue>
#include <stack>
using namespace std;

    // Continuously pop elements from the input queue and check if it is equal to the top of output queue or not, if it is not equal to the top of output queue then we will push the element to stack.
    // Once we find an element in input queue such the top of input queue is equal to top of output queue, we will pop a single element from both input and output queues, and compare the top of stack and top of output queue now. If top of both stack and output queue are equal then pop element from both stack and output queue. If not equal, go to step 1.
    // Repeat above two steps until the input queue becomes empty. At the end if both of the input queue and stack are empty then the input queue is permutable otherwise not.

bool stackPermutation(int in[],int op[],int n){
    queue<int>q1;
    for (int i = 0; i < n; i++) {
        /* code */
        q1.push(in[i]);
    }
    
    queue<int>q2;
    for (int i = 0; i < n; i++) {
        /* code */
        q2.push(op[i]);
    }
    stack<int>st;
    
    while(!q1.empty()){
        int val=q1.front();
        q1.pop();
        
        if(val==q2.front()){
            q2.pop();
            while(!st.empty()){
                if(q2.front()==st.top()){
                    q2.pop();
                    st.pop();
                } else {
                    break;
                }
            }
        }
        else{
            st.push(val);
        }
    }
    return (q1.empty() and q2.empty());
}

int main() {
    int input[] = {1, 2, 3};
  
    // Output Queue
    int output[] = {3,1,2};
  
    int n = 3;
    cout<<stackPermutation(input,output,n);
	return 0;
}