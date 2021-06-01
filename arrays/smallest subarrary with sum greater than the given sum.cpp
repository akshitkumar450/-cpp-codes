#include <bits/stdc++.h>
using namespace std;

// O(n^2)
int smallestSub(int arr[],int n,int sum){
    int smallestLen=INT_MAX;
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=i;j<n;j++){
            s=s+arr[j];
            if(s>sum) {
                smallestLen=min(smallestLen,j-i+1);
            }
        }
    }
    return smallestLen;
}

int smallestSubOptimized(int arr[],int n,int sum){
    int smallestLen=INT_MAX;
    int curSum=0;
    int start=0,end=0;
    while(end<n){
        //   Keep adding array elements while current sum
        // is smaller than or equal to sum
        while(curSum<=sum and end<n){
            curSum=curSum+arr[end];
            end++;
        }
        // if the curSum is greater than the sum keep removing the elements from the start 
        // and find the minlength
        while(curSum>sum and start<end){
            smallestLen=min(smallestLen,end-start);
            curSum=curSum-arr[start];
            start++;
        }
    }
    return smallestLen;
}

int main() {
 int arr[] = { 1, 4, 45, 6, 10, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum;
    cin>>sum;
    cout<<smallestSubOptimized(arr,n,sum);
	return 0;
}