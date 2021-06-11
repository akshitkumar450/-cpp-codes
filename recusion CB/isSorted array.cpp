#include <iostream>
using namespace std;

bool isSorted(int arr[],int n){
    if(n==0 or n==1) return true;
    
    // check if the first array is sorted then only call for next 
    if(arr[0]<arr[1] and isSorted(arr+1,n-1)){
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(isSorted(arr,n)){
        cout<<"sorted";
    } else{
        cout<<"not sorted";
    }
	return 0;
}