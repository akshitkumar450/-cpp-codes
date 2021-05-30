#include <iostream>
using namespace std;

void maxSumSubarray(int arr[],int n) {
    int curSum=0;
    int maxSum=0;
    // kadane algo
    for(int i=0;i<n;i++) {
        curSum=curSum+arr[i];
        if(curSum<0) {
            curSum=0;
        }
        maxSum=max(curSum,maxSum);
    }

    cout<<"maximum sum "<<maxSum;
}


int main() {
         int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    };
    maxSumSubarray(arr,n);
}
