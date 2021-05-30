#include <iostream>
using namespace std;

int* firstandlast(int arr[],int n,int key) {
    int lo=0;
    int high=n-1;
    int *ans=new int[2];
    ans[0]=-1;
    ans[1]=-1;
    // first occurence
    while(lo<=high) {
        int  mid=(lo+high)/2;
        if(arr[mid]==key) {
            // search for first in left part
            ans[0]=mid;
            high=mid-1;
            // return mid;
        } 
        else  if(arr[mid]<key) {
            lo=mid+1;
        } else if(arr[mid]>key){
            high=mid-1;
        }
    }
    // last occurence
     lo=0;
    high=n-1;
    while(lo<=high) {
        int  mid=(lo+high)/2;
        if(arr[mid]==key) { 
            // search for second in right part
            ans[1]=mid;
        lo=mid+1;
            // return mid;
        } 
        else  if(arr[mid]<key) {
            lo=mid+1;
        } else if(arr[mid]>key){
            high=mid-1;
        }
    }

    return ans;
}

int main() {
    int arr[]={1,1,2,2,2,2,5,5};
     int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
     int *result=firstandlast(arr,n,key);
     cout<<result[0]<< " "<<result[1];
}
