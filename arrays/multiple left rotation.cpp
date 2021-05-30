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
    d=d%n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);;
    reverse(arr,0,n-1);;
}

void display(int arr[],int n){
  for(int i=0;i<n;i++){
                 cout<<arr[i]<<" ";
             }
             cout<<endl;
         
}

int main() {
      int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
  
       int k,k1,k2,k3;
       cin>>k>>k1>>k2>>k3;
        leftrotate(arr,n,k);
        display(arr,n);
        int  arr1[] = {1, 3, 5, 7, 9};

        leftrotate(arr1,n,k1);
        display(arr1,n);
         int arr2[] = {1, 3, 5, 7, 9};

        leftrotate(arr2,n,k2);
         display(arr2,n);
         int arr3[] = {1, 3, 5, 7, 9};
         leftrotate(arr3,n,k3);
         display(arr3,n);

 
  
}
