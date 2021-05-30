#include <iostream>
using namespace std;
void rotate(int arr[],int n){
    int temp=arr[n-1];
    for(int i=n-1;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rotate(arr,n);
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
