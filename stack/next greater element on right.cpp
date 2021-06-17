#include <bits/stdc++.h>
using namespace std;

void nextGreaterElement(int arr[],int n){
    stack<int>st;
    for(int i=0;i<n;i++){
        // if stack is not empty and coming element is greater than the top of the stack
        // then pop till we have smaller elemnt on top of stack
        // if the incoming value is greater than top value ,we will pop from stack untill we have smaller value
        while(!st.empty() and st.top()<arr[i]){
           int val=st.top();
           st.pop();
           cout<<val<<"-> "<<arr[i]<<endl;
        } 
        // after poping out element which are smaller than me 
        // push myself in to stack for finding my next greater element
        st.push(arr[i]);       
    }

    // if element are left in stack means they have not any next greater element then print -1 for them
    while(!st.empty()){
        int val=st.top();
        st.pop();
        cout<<val<<"-> -1"<<endl;
    } 
}

int main() {
    int arr[7]={54,5,3,6,2,10,4};
    nextGreaterElement(arr,7);
	return 0;
}