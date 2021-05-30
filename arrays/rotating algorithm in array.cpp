#include <iostream>
using namespace std;
void reverse(int arr[],int start,int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void leftrotate(int arr[],int n,int d){
    if(d==0) return;
    d=d%n;  // if d is > than size of array
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);;
    reverse(arr,0,n-1);;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
   int d;
   cin>>d;
   leftrotate(arr,n,d);
      for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
