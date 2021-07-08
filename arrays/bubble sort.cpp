#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[],int n){
    // in bubble sort we have only n-1 iterations
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//better

class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        int n=arr.size();
        // n-1 iterations 
      for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
        return arr;
    }
};
int main() {
	    int n;
	    cin>>n;
	    int arr[n];
        // int n=sizeof(arr)/sizeof(int);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
      bubbleSort(arr,n);
       
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }

	return 0;
}