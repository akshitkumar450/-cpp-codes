#include <iostream>
#include<stack>
using namespace std;

void sortInsert(stack<int>&s,int val){
    if(s.empty() or val>s.top()){
        s.push(val);
        return;
    }
    int x=s.top();
    s.pop();
    sortInsert(s,val);
    s.push(x);
}

void sortStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int val=s.top();
    s.pop();
    sortStack(s);
    sortInsert(s,val);
}

int main() {
    stack<int>st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
    sortStack(st);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

	return 0;
}