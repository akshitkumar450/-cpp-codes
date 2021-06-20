#include <iostream>
#include <deque>
using namespace std;

void printFirstNegativeInteger(int arr[], int n, int k){
    // flag to check whether window contains
    // a negative integer or not
    bool flag;
    // Loop for each subarray(window) of size k
    for (int i = 0; i<=(n-k); i++) {
        flag = false;
        // traverse through the current window
        for (int j = 0; j<k; j++) {
            // if a negative integer is found, then
            // it is the first negative integer for
            // current window. Print it, set the flag
            // and break
            if (arr[i+j] < 0) {
                cout << arr[i+j] << " ";
                flag = true;
                break;
            }
        }
        // if the current window does not
        // contain a negative integer
        if (!flag)
            cout << "0" << " ";
    }   
}


void printFirstNegativeInteger(int arr[],int n,int k){
    deque<int>q; // store index
    // process the first k elements(first window)
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            q.push_back(i);
        }
    }
    
    for(int i=k;i<n;i++){
        // print element for previous window
        // if it is empty means it has not negative elements so print 0 
        if(!q.empty()){
            cout<<arr[q.front()]<<" ";
        } else {
            cout<<"0"<<" ";
        }
        // remove elements which are out of window
        while(!q.empty() and (q.front()<=i-k)){
            q.pop_front();
        }
        // add new elements which are negative
        if(arr[i]<0){
            q.push_back(i);
        }
    }
    // print for the last window
         if(!q.empty()){
            cout<<arr[q.front()]<<" ";
        } else {
            cout<<"0"<<" ";
        }
}

int main() {
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, n, k);
    // process first k elements separately
 
   

	return 0;
}