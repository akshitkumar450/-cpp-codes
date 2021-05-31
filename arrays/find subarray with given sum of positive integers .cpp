#include <iostream>
using namespace std;

// Algorithm:  

//     Traverse the array from start to end.
//     From every index start another loop from i to the end of array to get all subarray starting from i, keep a variable sum to calculate the sum.
//     For every index in inner loop update sum = sum + array[j]
//     If the sum is equal to the given sum then print the subarray.

// O(n^2)

void subArraySum(int arr[],int n,int sum) {
    int curSum,i,j;
    for(int i=0;i<n;i++) {
        curSum=arr[i];
        for(int j=i+1;j<=n;j++) {
            if(curSum==sum) {
                cout<<"subArraySum is present "<<i<< " "<<j-1;
                return;
                // if current sum becomes greater or we have reached the end of the array
            } else if(curSum>sum || j==n) {
                break;
            }
            // calculate the current sum
            curSum=curSum+arr[j];
        }
    }
    cout<<"not found";
    return ;
}


    // Create three variables, l=0, sum = 0
    // Traverse the array from start to end.
    // Update the variable sum by adding current element, sum = sum + array[i]
    // If the sum is greater than the given sum, update the variable sum as sum = sum – array[l], and update l as, l++.
    // If the sum is equal to given sum, print the subarray and break the loop.

// O(N)
void subArraySumOptimized(int arr[],int n,int sum) {
    int curSum=arr[0],start=0,i;
    for(int i=1;i<=n;i++) {
        while(curSum>sum && start <i-1) {
            curSum=curSum-arr[start];
            start++;
        }
        if(curSum==sum) {
              cout<<"subArraySum is present "<<start<< " "<<i-1;
                return;
        } 
        // if array has elements calculate the sum
        if(i<n) {
            curSum=curSum+arr[i];
        }
    }
    cout<<"not present";
    return;
}

int main() {
   int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
// 	for(int i=0;i<n;i++) {
// 	    cout<<arr[i]<<" ";
// 	}
	return 0;
}