#include <iostream>
using namespace std;

stack<int>st;
int min;


void push(int val){
    // for the first inserstion 
    // if stack is empty then just push into stack and set the minvalue to that
    if(st.empty()){
        st.push(val);
        min=val;
        // if the stack is not empty and value is greater than min ,
        // just add to stack and dont change the minvalue
    } else if(val>=min){
        st.push(val);

        // if the value is smaller than the min value
        // we will manipulate the incoming value and push that to the stack
        // and will store the original number in min 
        // this will indicate the special step in the stack while popping and top
        // we will store val+val-min in this case(as a fake value)
        // and the original value we in min
    } else if(val<min){
        st.push(val+val-min);  // can be used as a detection 
        min=val;
    }
}

int top(){
    if(st.size()==0) return -1;
    // if top value is greater than the min value means it top vale is not manipulated 
    // so we can just return that top value
    else if(st.top()>=min){
        return st.top();
    }
    // if top value is smaller than min ,
    // means we have manipulated the value and
    // we have stored the original value in min while pushing
    else if(st.top()<min){
        return min;
    }
}

int pop(){
      if(st.size()==0) return -1;
    // if top value is greater than the min value means it top vale is not manipulated 
    // so we can just return that top value
    else if(st.top()>=min){
        return st.top();
    }
    // if top value is smaller than min ,
    // means we have manipulated the value and
    // we have stored the original value in min while pushing

    // when popping the min value should be reset to the old min value
    else if(st.top()<min){
        int originalval=min; // save the new min value
        min=2*min-st.top(); // reset to old min value (bcz at top we have stored val+val-min)
        return  originalval; 
    }
}

int size(){
    return st.size();
}
int minimun(){
    if(st.empty()) return -1;
    return min;
}

int main() {
	cout<<"GfG!";
	return 0;
}