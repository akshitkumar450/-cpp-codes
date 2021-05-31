#include <iostream>
using namespace std;


// Maintain two indexes. Initialize first index left as 0 and second index right as n-1.
// Do following while left < right 
// a) Keep incrementing index left while there are 0s at it 
// b) Keep decrementing index right while there are 1s at it 
// c) If left < right then exchange arr[left] and arr[right]

void sort012(int arr[],int n) {
    int i=0,j=n-1;
    while(i<j) {
        while(i<j && arr[i]==0) {
            i++;
        } 
        while(i<j && arr[j]==1) {
            j--;
        }
        if(i<j) {
            arr[i]=0;
            arr[j]=1;
            i++;
            j--;
        }
    }   
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
 int arr[] = { 0, 1, 1, 0, 1,  1, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sort012(arr, n);
    printArray(arr, n);
	return 0;
}