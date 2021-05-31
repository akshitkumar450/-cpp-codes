#include <iostream>
using namespace std;

int duplicate(int arr[],int n) {
    int temp[n];
    // include first element 
    temp[0]=arr[0];
    // size of the temp array 
    int res=1;
    // start from second el
    for(int i=1;i<n;i++) {
        if(temp[res-1]!=arr[i]) {
            temp[res]=arr[i];
            res++;
        }
    }
// copy elements from temp to arr
    for(int i=0;i<res;i++) {
        arr[i]=temp[i];
    }
    return res;
}

int main() {
 
 int arr []={10,20,30,40,50,60,70,80,90,90};
 int n=10;
 cout<<duplicate(arr,n);
}
