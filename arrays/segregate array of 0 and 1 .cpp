#include <iostream>
using namespace std;

void segregate0and1(int arr[],int n) {
       int cnt=0;
    for(int i=0;i<N;i++) {
        if(A[i]==0) {
            int temp=A[i];
            A[i]=A[cnt];
            A[cnt]=temp;
            // swap(A[i],A[cnt]);
            cnt++;
        }
    }
}

//  another method
// first count no of zeros 
// then print zero count no of times 
//  and then and print 1 n-count times
int main() {
 int arr[] = { 0, 1, 0, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    segregate0and1(arr, n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
	return 0;
}