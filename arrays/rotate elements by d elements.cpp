#include <iostream>
using namespace std;

// for rotating  one element each time 
void rotate(int arr[],int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}

void leftRotate(int arr[],int n,int d){
    // rotate the elements d times
    for(int i=0;i<d;i++){
        rotate(arr,n);
    }
}

int main() {
   int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
   int d;
   cin>>d;

   leftRotate(arr,n,d);
      for(int i=0;i<n;i++){
        cout<<arr[i];
    }


}
