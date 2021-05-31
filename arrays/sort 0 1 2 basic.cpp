#include <iostream>
using namespace std;

void sort012(int arr[],int n){
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++) {
        if(arr[i]==0 )c0++;
        else if(arr[i]==1) c1++;
        else if(arr[i]==2) c2++;
    }
    
    for(int i=0;i<c0;i++) {
        arr[i]=0;
    }
    for(int i=c0;i<c0+c1;i++) {
        arr[i]=1;
        
    }
    for(int i=c0+c1;i<n;i++) {
    arr[i]=2;
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
 int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sort012(arr, n);
    printArray(arr, n);
	return 0;
}