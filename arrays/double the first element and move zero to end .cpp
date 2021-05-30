#include <iostream>
using namespace std;

void moveZeroToend(int arr[],int n) {
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(arr[i]!=0) {
            swap(arr[i],arr[cnt]);
            cnt++;
        }
    }
}

void doubleFirstEl(int arr[],int n) {
    if(n==1) return ;
    for(int i=0;i<n-1;i++) {
        if((arr[i]!=0) && arr[i]==arr[i+1]) {
            arr[i]=2*arr[i];
            arr[i+1]=0;
            i++;
        }
    }
    moveZeroToend(arr,n);
}

int main() {
    int arr[] = { 0, 2, 2, 2, 0, 6, 6, 0, 0, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    doubleFirstEl(arr,n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
