#include <iostream>
using namespace std;

int first(int arr[],int n,int key){
    // base case
    if(n==0){
        return -1;
    } 
    // rec case
    if(arr[0]==key){
        return 0;
    }
    // check in the smaller array
    int index=first(arr+1,n-1,key);
    // if not found in smaller array return -1
    if(index==-1){
        return -1;
    }
    // if found in smaller array return by adding 1
    return index+1;
}

int main() {
    int arr[]={1,2,3,7,4,5,6,7,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    cout<<first(arr,n,key);
    return 0;
}