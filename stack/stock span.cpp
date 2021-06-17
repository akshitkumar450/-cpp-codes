#include <bits/stdc++.h>
using namespace std;

void stockSpan(int arr[],int n){
    // we will store index of the elements not the value
    stack<int>st;
    for(int i=0;i<n;i++){
        // if the incoming value is greater than the value of the index at top then we pop it
        // 
        while(!st.empty() and arr[st.top()]<arr[i]){
            st.pop();
        }      
        int days;
        // if the stack is not empty means we have some value which is greater
        if(!st.empty()){
            days=i-st.top();
        } else{
            // means current element have popped all elements on its left 
            // it the maximum element will now
            days=i+1;
        }
        cout<<arr[i]<<"-> "<<days<<endl;
        st.push(i);
    }  
}

int main() {
    int arr[7]={100,80,60,70,60,75,85};
    stockSpan(arr,7);
	return 0;
}