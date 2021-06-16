// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#
#include <iostream>
using namespace std;

   bool find3Numbers(int A[], int n, int X) {
        for(int i=0;i<n-2;i++) {
        for(int j=i+1;j<n-1;j++) {
            for(int k=j+1;k<n;k++){
                if(A[i]+A[j]+A[k]==X) {
                    cout<<A[i]<<" "<<A[j]<<" "<<A[k];
                    return 1;
                }
            }
        }
    }
    return 0;
 }
 
//  Algorithm : 

//     Sort the given array.
//     Loop over the array and fix the first element of the possible triplet, arr[i].
//     Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum, 
//         If the sum is smaller than the required sum, increment the first pointer.
//         Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
//         Else, if the sum of elements at two-pointer is equal to given sum then print the triplet and break.
  
   bool find3Numbers1(int A[], int n, int X) {
      int l,r;
      sort(A,A+n);
      for(int i=0;i<n-2;i++) {
          l=i+1,r=n-1;
          while(l<r) {
              if(A[i]+A[l]+A[r]==X) {
                  return 1;
              } else if(A[i]+A[l]+A[r]<X) {
                  l++;
              } else { // A[i] + A[l] + A[r] > sum
                  r--;
              }
          }
      }
      return 0;
    }
int main() {
	int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int X = 22; 
    int n= sizeof(A) / sizeof(A[0]); 
    find3Numbers(A, n, X); 
    find3Numbers1(A, n, X); 
	return 0;
}