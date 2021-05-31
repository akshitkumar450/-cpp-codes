#include <iostream>
using namespace std;

void sort012(int arr[],int n) {
    int low=0,mid=0,high=n-1;
    while(mid<=high) {
            if(a[mid]==0) {
                swap(a[low],a[mid]);
                mid++;
                low++;
            } else if(a[mid]==1) {
                mid++;
            } else if(a[mid]==2){
                swap(a[mid],a[high]);
                high--;
            }
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