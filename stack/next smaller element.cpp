#include <bits/stdc++.h>
using namespace std;

void nextSmaller(int arr[],int n){
    // store index 
    stack<int>st;
    // for storing the answer
    int temp[n];
    for(int i=0;i<n;i++){
        // if the current element is smaller then the value of the index present at the top
        // then we will pop and we will store the answer for that in the index in temp array
        // we will pop when current element value is smaller than the index value at top
        while(!st.empty() and arr[st.top()]>arr[i]){
            int val=st.top();
            st.pop();
            
            // put the current element on the smaller value index
             temp[val]=arr[i];
        }
        st.push(i);
    }
    // if element are left in the stack means they dont have any smaller element
    // then we will just put -1 on the index value 
    while(!st.empty()){
        temp[st.top()]=-1;
        st.pop();
    }
    
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" "<<endl;
    }
}

int main() {
   int arr[7]={2,3,1,4,6,5,0};
    nextSmaller(arr,7);
	return 0;
}